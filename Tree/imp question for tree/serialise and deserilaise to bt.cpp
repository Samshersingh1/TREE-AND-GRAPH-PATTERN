// understand the question first what to do ::  given a tree store this   in the string and then 
// from this string  convert this into tree ...this is design problem 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
             string s="";
             if(root==NULL) return s;
             queue<TreeNode*>q;
             q.push(root);
             while(!q.empty()){ 
                TreeNode*temp=q.front(); 
                 q.pop();
                if(temp){
                    s+=to_string(temp->val)+',';
                    q.push(temp->left);
                    q.push(temp->right);
                } 
                else{
                     s+="#,";
                }
             } 
             return s;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
             if(data.size()==0) return NULL; 
              stringstream ss(data);    //string flow
              string val;
             getline(ss,val,',') ; 
              //this fuction "Read characters from the stream ss until a comma (,) is found, and store them in the string val."
             TreeNode*root=new TreeNode(stoi(val));  //this will be root
              queue<TreeNode*>q;
              q.push(root);
            // int j=1;
              while(!q.empty()){  
                  TreeNode*temp=q.front();
                    q.pop();  
                     if(getline(ss,val,',')){
                        if(val!="#") {
                            TreeNode*left=new TreeNode(stoi(val));
                            temp->left=left;
                            q.push(temp->left);
    
                        } 
                     } 
                     if(getline(ss,val,',')){
                        if(val!="#") {
                           TreeNode*right=new TreeNode(stoi(val));
                            temp->right=right;
                            q.push(temp->right);
                        }     
                     }   
    
             }   
    
             return root;
        }
    }; 
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));