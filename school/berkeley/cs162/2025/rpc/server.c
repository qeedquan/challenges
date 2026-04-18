#include <rpc/rpc.h>
#include "kv_store.h"

int *
example_1_svc(int *integer, struct svc_req *req)
{
	*integer += 1;
	return integer;
}

char **
echo_1_svc(char **string, struct svc_req *req)
{
	return string; 
}
