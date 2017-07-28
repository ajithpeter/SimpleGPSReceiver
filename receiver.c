#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

typedef struct _receiver_context
{
	FILE* fptr;

} rctx;

void process_sample(rctx* ctx, unsigned char sample)
{
	double sample1 = 0.0;
	double sample2 = 0.0;
	double sample3 = 0.0;
	double sample4 = 0.0;


}

int process_samples(rctx* ctx, char* filename)
{
	unsigned char buffer[512];
	unsigned int num_bytes;
	unsigned int i;

	ctx->fptr = fopen(filename, "r");
	if (ctx->fptr == NULL)
	{
		fprintf(stderr, "Error opening file : %s\n", filename);
		return -1;	
	}

	while (!feof(fptr))
	{
		num_bytes = fread(buffer, sizeof(unsigned char), 512, ctx->fptr);
		if ((num_bytes != 512) && (feof(fptr) != 0))
		{
			fprintf(stderr, "Error opening file : %s\n", filename);
			fclose(fptr);
			return -1;
		}
		for (i = 0; i < num_bytes; i++) process_sample(ctx, buffer[i]);
	}

	fclose(ctx->fptr);
	return 0;
}

int main(int argc, char** argv)
{
	rctx context;

	if (argc < 2)
	{
		printf("Usage : %s <sample file name>\n", argv[0]);
		return -1;
	}

	return process_samples(&context, argv[1]);
}