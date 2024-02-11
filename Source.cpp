#include <stdio.h>
#include <stdint.h>
#include <assert.h>


typedef uint8_t byte;
typedef struct
{
	byte i, j;
	byte S[256];
} Rc4State;

void swap(byte* a, byte* b)
{
	byte temp = *a;
	*a = *b;
	*b = temp;
}

/*Initialization & initial permutation
also initialize i&j counters in state for stream generation*/
void initState(const byte K[256], int keylen, Rc4State* state)
{
	byte T[256];
	assert(keylen >= 1 && keylen <= 256);
	int i;
	for (i = 0; i < 256; i++) {
		state->S[i] = i;
		T[i] = K[i % keylen];
	}

	//Initial permutation of S
	byte* S = state->S;
	int j = 0;
	for (i = 0; i < 256; i++) {
		j = (j + S[i] + T[i]) % 256;
		swap(&S[i], &S[j]);
	}

	//Initialize counters in state
	state->i = state->j = 0;
}

/*Encrypt/Decrypt text by XORing with next byte of keystream*/
byte crypt(byte text, Rc4State* state)
{
	byte t, k;
	byte* i = &(state->i), * j = &(state->j);
	byte* S = state->S;
	*i = (*i + 1) % 256;
	*j = (*j + S[*i]) % 256;
	swap(&S[*i], &S[*j]);
	t = (S[*i] + S[*j]) % 256;
	k = S[t];

	return text ^ k;
}

static byte rc4CryptByte(Rc4State* state, byte plainText)
{
	byte* S = state->S;
	byte i = ++(state->i);
	byte j = (state->j += S[i]);

	swap(&S[i], &S[j]);
	byte t = S[i] + S[j];
	byte k = S[t];

	return plainText ^ k;
}

void rc4Crypt(Rc4State* state, byte text[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		text[i] = rc4CryptByte(state, text[i]);
	}
}