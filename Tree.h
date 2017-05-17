/*
	A libs that include
	kinds of Tree function.
*/
#include <cstdio>
#include <queue>

using namespace std;


//The struct of three node
template <typename t>
class Tree_node
{
public:
	Tree_node(const int Kind_of_tree = 2)
	{
		//Node pointer array.
		//The number of pointer is def by the users.
		_Pointer_array = new Tree_node* [ Kind_of_tree ];
		for(int i = 0 ; i < Kind_of_tree ; i++)
			_Pointer_array[i] = NULL;

		Num_of_node = Kind_of_tree;
	}
private:
	int Num_of_node;

	t _Element;
	Tree_node **_Pointer_array;
};

template <typename t>
class Tree
{
public:
	Tree(const int Kind_of_tree = 2)
	{
		_Tree_node = new Tree_node<t>( Kind_of_tree );
	}

	virtual void init(t *Array,int Length);
	virtual void init_step();
	virtual void pre();
	virtual void in();
	virtual void after();
	virtual void del();
	virtual void ins();
private:
	int _Tree_pointer;
	Tree_node<t> *_Tree_node;
};

template <typename t>
class Binary_Tree
{
public:
	Binary_Tree()
	{
		_Tree_pointer = 2;

		_Head_node = new Tree_node<t>( _Tree_pointer );
	}

	void init(t *Array,int Length);
	void init_step();
private:
	int _Tree_pointer;
	Tree_node<t> *_Head_node;
};


//init by array
template <typename t>
void Binary_Tree<t>::init(t *Array,int Length)
{
	Tree_node<t> *_Node;
	Tree_node<t> *Node_temp;
	int Array_walker;
	int Node_neddle;
	int Cnt_of_node;

	Array_walker = 0;
	Cnt_of_node = _Head_node->Num_of_node;
	queue < Tree_node<t> > _Node_queue;

	_Node = _Head_node;
	_Node_queue.push(_Node);

	while( _Node_queue.size() && Array_walker != Length-1 )
	{
		_Node = _Node_queue.front();
		_Node_queue.pop();

		Node_neddle %= Cnt_of_node;
		Node_temp = new Tree_node<t>;
		
		Node_temp -> _Element = Array[Array_walker];
		_Node->_Pointer_array[Node_neddle] = Node_temp;

		_Node_queue.push(Node_temp);
	}
}

template <typename t>
void Binary_Tree<t>::init_step()
{
	t Temp;
	t Break_temp;

	Tree_node<t> *_Node;
	

	cout<<"cin the break pointer: ";cin>>Break_temp;

	while(cin>>Temp && Temp != Break_temp)
	{
		_Head_node
	}
}

