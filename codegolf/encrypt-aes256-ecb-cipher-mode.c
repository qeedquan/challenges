/*

The goal is (hopefully) clear: create the shortest code (in bytes) that implements the AES256 ECB cipher mode. Either convert the result to Base64 or output a array of bytes. The input contains two parts. The first part is the stuff to encrypt, and the second part (separated by newlines) is the secret key. You do not need to decrypt it!

Test cases!
Input:

AES Encryption!
averygoodsecretpasswordthatsgood
Output:

VBWQy7umRdabP1xs2y1Oqg==
You may output as an array of bytes too, if you wish.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

typedef unsigned char uchar;

char *
base64enc(uchar *src, size_t len)
{
	BIO *bmem, *b64;
	BUF_MEM *bp;
	char *dst;

	dst = NULL;
	b64 = BIO_new(BIO_f_base64());
	if (!b64)
		goto error;

	bmem = BIO_new(BIO_s_mem());
	if (!bmem)
		goto error;

	b64 = BIO_push(b64, bmem);
	BIO_write(b64, src, len);
	BIO_flush(b64);
	BIO_get_mem_ptr(b64, &bp);

	dst = calloc(1, bp->length + 1);
	if (!dst)
		goto error;

	if (bp->length)
		memcpy(dst, bp->data, bp->length - 1);

	if (0) {
	error:
		free(dst);
		dst = NULL;
	}

	BIO_free_all(b64);
	return dst;
}

int
encrypt(uchar *key, uchar *src, size_t len, uchar *dst)
{
	EVP_CIPHER_CTX *ctx;
	int r;

	r = 0;
	ctx = EVP_CIPHER_CTX_new();
	if (!ctx) {
		errno = ENOMEM;
		goto error;
	}

	if (EVP_EncryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, key, NULL) != 1)
		goto einval;

	if (EVP_EncryptUpdate(ctx, dst, &r, src, len) != 1)
		goto einval;

	if (EVP_EncryptFinal_ex(ctx, dst, &r) != 1)
		goto einval;

	if (0) {
	einval:
		errno = EINVAL;
	error:
		r = -errno;
	}

	EVP_CIPHER_CTX_free(ctx);
	return r;
}

void
test(uchar *key, uchar *txt, size_t txtlen, const char *expected)
{
	uchar enc[128];
	int enclen;
	char *str;

	enclen = encrypt(key, txt, txtlen, enc);
	str = base64enc(enc, enclen);
	assert(str);

	printf("%s\n", str);
	assert(!strcmp(str, expected));

	free(str);
}

int
main(void)
{
	uchar key[] = "averygoodsecretpasswordthatsgood";
	uchar txt[] = "AES Encryption!";

	test(key, txt, sizeof(txt) - 1, "VBWQy7umRdabP1xs2y1Oqg==");
	return 0;
}
