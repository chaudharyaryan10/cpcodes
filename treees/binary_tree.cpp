
//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root, vector<int> &vec){
        if(vec.size()==0)
          return;
        queue<node*>q;
        q.push(root);
        int i=1;
        while(!q.empty() && i<vec.size()){
            node* curr=q.front();
            q.pop();
            if(vec[i]!=-1){
                curr->left=newNode(vec[i]);
                q.push(curr->left);
            }
            i++;
            if(i<vec.size() && vec[i]!=-1){
                curr->right=newNode(vec[i]);
                q.push(curr->right);
            }
            i++;
            
        }
    }

};
