 /* in this traversal we will see how can we traverse (pre,in,post) in recursivly ways...  using stack...
    
  */ 

  // in PREORDER  traversal using stack 

  class Solution {
     public:
         vector<int> preorderTraversal(TreeNode* root) {   
               stack<TreeNode*>st;
               vector<int>v;
             if(root==NULL) return v;
                   st.push(root);
                 while(st.size()>0){ 
                     TreeNode*Node=st.top();  //we will not use for loop till size beacuse we first want left tot traverse 
                        st.pop();
                      if(Node->right!=NULL) st.push(Node->right); //we will push right first because stack works fifo wewant left at top
                     if(Node->left!=NULL)  st.push(Node->left);    
                      v.push_back(Node->val); 
                      // st.pop();
             }
             return v;
         }
     };    

//INORDER TRAVERSAL USING STACK 

/* this is imp for this we will use real stack as comapare to recursive stack  
  Step 0:: move left until you root beacames NULL;
  Step 1: when my root node will null top ele of stack will print 
  Step 2: after printing the top ele of stack we will delete it 
  Step 3: then we will move right side   
  */ 

class Solution {
     public:
         vector<int> inorderTraversal(TreeNode* root) {
              stack<TreeNode*>st;
               vector<int>a;
             if(root==NULL) return a;
             //  st.push(root); 
              while(root!=NULL ||st.size()>0){
                 while(root!=NULL){
                     st.push(root);
                     root=root->left;
                 }  
                root= st.top();
                  st.pop();
                 a.push_back(root->val);
                 root=root->right; 
                    
                 //now the things which will again come  
             }    
             return a;
         }   
     };      
     
     // POST ORDER TRAVERSAL USING STACK (1,2)...

     /* THIS IS IMPORTANT TO LEARN..
       
     */ 

     class Solution {
          public:
              vector<int> postOrder(Node* node) {
                  vector<int> v;
                  stack<Node*> st;
                  Node* lastVisited = nullptr;
                  
                  while (!st.empty() || node != nullptr) {
                      if (node != nullptr) { // Go left
                          st.push(node);
                          node = node->left;
                      } 
                      else {
                          Node* temp = st.top();
                          if (temp->right != nullptr && temp->right != lastVisited) { 
                              node = temp->right; // Move to the right subtree
                          } 
                          else { 
                              v.push_back(temp->data);
                              lastVisited = temp;
                              st.pop();
                          }
                      }
                  }
                  
                  return v;
              }
          };
          