//tree node class for BST

template <class type>
class node{
public:
  node<type>();
  node<type>(int k, type d); //k = key, d = data
  ~node<type>();

  int key;
  type data;
  node<type> *left;
  node<type> *right;
};

//default constructor
template <class type>
node<type>::node(){
  key = 0;
  data = NULL;
  left = NULL;
  right = NULL;
}

//overloaded constructor
template <class type>
node<type>::node(int k, type d){
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

//destructor
template <class type>
node<type>::~node(){
  delete left;
  delete right;
}
