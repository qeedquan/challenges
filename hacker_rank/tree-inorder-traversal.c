/*

In this challenge, you are required to implement inorder traversal of a tree.

Complete the  function in your editor below, which has  parameter: a pointer to the root of a binary tree. It must print the values in the tree's inorder traversal as a single line of space-separated values.

Input Format

Our hidden tester code passes the root node of a binary tree to your $inOrder* function.

Constraints



Output Format

Print the tree's inorder traversal as a single line of space-separated values.

Sample Input

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4

Sample Output

1 2 3 4 5 6

Explanation

The tree's inorder traversal results in 1 2 3 4 5 6 as the required result.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;
typedef struct Slice Slice;

struct Slice {
	int val[128];
	size_t len;
};

struct Node {
	int val;
	Node *left;
	Node *right;
};

void
print(Slice *slice)
{
	size_t i;

	for (i = 0; i < slice->len; i++)
		printf("%d ", slice->val[i]);
	printf("\n");
}

void
append(Node *node, void *userdata)
{
	Slice *slice;

	slice = userdata;
	if (slice->len < nelem(slice->val))
		slice->val[slice->len++] = node->val;
}

// https://www.educative.io/answers/what-is-morris-traversal
void
inorder(Node *root, void (*func)(Node *, void *), void *userdata)
{
	Node *cur, *prev;

	cur = root;
	while (cur != NULL) {
		if (cur->left == NULL) {
			func(cur, userdata);
			cur = cur->right;
		} else {
			// Find the previous (prev) of cur
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
				prev = prev->right;

			// Make cur as the right child of its previous
			if (prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			}
			// fix the right child of previous
			else {
				prev->right = NULL;
				func(cur, userdata);
				cur = cur->right;
			}
		}
	}
}

void
test(Node *root, Slice *result)
{
	Slice slice;

	memset(&slice, 0, sizeof(slice));
	inorder(root, append, &slice);
	print(&slice);
	assert(!memcmp(result, &slice, sizeof(slice)));
}

int
main(void)
{
	Node *t1 = &(Node){
	    .val = 1,
	    .right = &(Node){
	        .val = 2,
	        .right = &(Node){
	            .val = 5,
	            .left = &(Node){
	                .val = 3,
	                .right = &(Node){
	                    .val = 4,
	                },
	            },
	            .right = &(Node){
	                .val = 6,
	            },
	        },
	    },
	};
	Slice *r1 = &(Slice){
	    .val = {1, 2, 3, 4, 5, 6},
	    .len = 6,
	};

	Node *t2 = &(Node){
	    .val = 4,
	    .left = &(Node){
	        .val = 2,
	        .left = &(Node){
	            .val = 1,
	        },
	        .right = &(Node){
	            .val = 3,
	        },
	    },
	    .right = &(Node){
	        .val = 5,
	    },
	};
	Slice *r2 = &(Slice){
	    .val = {1, 2, 3, 4, 5},
	    .len = 5,
	};

	test(t1, r1);
	test(t2, r2);

	return 0;
}
