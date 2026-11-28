%{

Cosine embedding loss measures whether two vectors are similar or dissimilar based on a label. It is commonly used in metric learning and siamese networks to learn embeddings where similar items are close and dissimilar items are far apart in cosine space.

Given two vectors, a label (+1 for similar, -1 for dissimilar), and a margin, compute the cosine embedding loss.

Formula
First compute the cosine similarity:

cos(x1, x2) = dot(x1, x2) / (norm(x1)*norm(x2))

Then compute the loss based on the label:

L = 1 - cos(x1, x2)               if label = 1
L = max(0, cos(x1, x2) - margin)  if label = -1

Return the cosine embedding loss as a float.

Examples
Input: x1 = [1, 0, 0], x2 = [1, 0, 0], label = 1, margin = 0

Output: 0.0

Explanation: Identical vectors have cosine similarity 1, so the similar-pair loss is 0.

Input: x1 = [1, 0, 0], x2 = [0, 1, 0], label = 1, margin = 0

Output: 1.0

Hint 1
Use zip with sum to compute the dot product and each squared norm.

Hint 2
Choose the loss branch from label after computing cosine similarity.

Requirements
Compute cosine similarity as dot product divided by the product of norms
For label = 1 (similar): return 1 - cosine_similarity
For label = -1 (dissimilar): return max(0, cosine_similarity - margin)
Return a single float
Constraints
Both vectors have the same length and at least one element
Vectors are non-zero (norms > 0)
label is either 1 or -1
margin >= 0
Return a single float
Time limit: 300 ms

%}

function L = cosine_embedding_loss(x1, x2, label, margin)
	cosine = dot(x1, x2) / (norm(x1)*norm(x2));
	L = 0;
	if label == 1
		L = 1 - cosine;
	elseif label == -1
		L = max(0, cosine - margin);
	end
end

cosine_embedding_loss([1 0 0], [1 0 0], 1, 0)
cosine_embedding_loss([1 0 0], [0 1 0], 1, 0)
