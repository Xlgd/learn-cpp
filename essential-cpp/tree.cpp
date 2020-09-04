#include <iostream>
using namespace std;

template <typename elemType>
class BinaryTree;


template <typename valType>
class BTnode {
	friend class BinaryTree<valType>;
public:
	BTnode(const valType& val);
	void insert_value(const valType& val);
	static void lchild_leaf(BTnode* leaf, BTnode* subtree);
	void remove_value(const valType& val, BTnode*& prev);
	void preorder(BTnode* pt, ostream& os) const;
	void inorder(BTnode* pt, ostream& os) const;
	void postorder(BTnode* pt, ostream& os) const;
	void display_val(BTnode* pt, ostream& os) const;
private:
	valType _val;
	int _cnt;
	BTnode* _lchild;
	BTnode* _rchild;
};

template <typename elemType>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);

	bool empty() { return _root == 0; }
	void clear() {
		if (_root) {
			clear(_root);
			_root = 0;
		}
	}

	void insert(const elemType& elem);
	void remove(const elemType& elem);
	void remove_root();

	void inorder() const { _root->inorder(_root, cout); }
	void postorder() const { _root->postorder(_root, cout); }
	void preorder() const { _root->preorder(_root, cout); }

private:
	BTnode<elemType>* _root;
	void copy(BTnode<elemType>* tar, BTnode<elemType>* src);
	void clear(BTnode<elemType>*);

};

template <typename valType>
BTnode<valType>::BTnode(const valType& val) : _val(val) {
	_cnt = 1;
	_lchild = _rchild = 0;
}

template <typename valType>
void BTnode<valType>::
lchild_leaf(BTnode* leaf, BTnode* subtree) {
	while (subtree->_lchild) {
		subtree = subtree->_lchild;
	}
	subtree->_lchild = leaf;
}

template <typename valType>
void BTnode<valType>::
insert_value(const valType& val) {
	if (val == _val) {
		_cnt++;
		return;
	}

	if (val < _val) {
		if (!_lchild) {
			_lchild = new BTnode(val);
		}
		else {
			_lchild->insert_value(val);
		}
	}
	else {
		if (!_rchild) {
			_rchild = new BTnode(val);
		}
		else {
			_rchild->insert_value(val);
		}
	}
}

template <typename valType>
void BTnode<valType>::
remove_value(const valType& val, BTnode*& prev) {
	if (val < _val) {
		if (!_lchild) {
			return;
		}
		else {
			_lchild->remove_value(val, _lchild);
		}
	}
	else if (val > _val) {
		if (!_rchild) {
			return;
		}
		else {
			_rchild->remove_value(val, _rchild);
		}
	}
	else {
		if (_rchild) {
			prev = _rchild;
			if (_lchild) {
				if (!prev->_lchild) {
					prev->_lchild = _lchild;
				}
				else {
					BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
				}
			}
		}
		else {
			prev = _lchild;
		}
		delete this;
	}
}

template <typename valType>
void BTnode<valType>::
preorder(BTnode* pt, ostream& os) const {
	if (pt) {
		display_val(pt, os);
		if (pt->_lchild) {
			preorder(pt->_lchild, os);
		}
		if (pt->_rchild) {
			preorder(pt->_rchild, os);
		}
	}
}

template <typename valType>
void BTnode<valType>::
inorder(BTnode* pt, ostream& os) const {
	if (pt) {
		if (pt->_lchild) {
			inorder(pt->_lchild, os);
		}
		display_val(pt, os);
		if (pt->_rchild) {
			inorder(pt->_rchild, os);
		}
	}
}

template <typename valType>
void BTnode<valType>::
postorder(BTnode* pt, ostream& os) const {
	if (pt) {
		if (pt->_lchild) {
			postorder(pt->_lchild, os);
		}
		if (pt->_rchild) {
			postorder(pt->_rchild, os);
		}
		display_val(pt, os);
	}
}

template <typename valType>
void BTnode<valType>::
display_val(BTnode* pt, ostream& os) const {
	os << pt->_val << " ";
}

template <typename elemType>
void BinaryTree<elemType>::
remove_root() {
	if (!_root) {
		return;
	}

	BTnode<elemType>* tmp = _root;
	if (_root->_rchild) {
		_root = _root->_rchild;

		if (tmp->_lchild) {
			BTnode<elemType>* lc = tmp->_lchild;
			BTnode<elemType>* newlc = _root->_lchild;
			if (!newlc) {
				_root->_lchild = lc;
			}
			else {
				BTnode<elemType>::lchild_leaf(lc, newlc);
			}
		}
	}
	else {
		_root = _root->_lchild;
	}
	delete tmp;
}

template <typename elemType>
void BinaryTree<elemType>::
clear(BTnode<elemType>* pt) {
	if (pt) {
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template <typename elemType>
BinaryTree<elemType>::~BinaryTree() {
	clear();
}

template <typename elemType>
BinaryTree<elemType>::BinaryTree(): _root(0) {}

template <typename elemType>
BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs) {
	copy(_root, rhs._root);
}

template <typename elemType>
BinaryTree<elemType>&
BinaryTree<elemType>::operator=(const BinaryTree& rhs) {
	if (this != &rhs) {
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template <typename elemType>
void
BinaryTree<elemType>::
insert(const elemType& elem) {
	if (!_root) {
		_root = new BTnode<elemType>(elem);
	}
	else {
		_root->insert_value(elem);
	}
}

template <typename elemType>
void
BinaryTree<elemType>::
remove(const elemType& elem) {
	if (_root) {
		if (_root->_val == elem) {
			remove_root();
		}
		else {
			_root->remove_value(elem, _root);
		}
	}
}