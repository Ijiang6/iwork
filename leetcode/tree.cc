/*
 *
 *创建二叉树
 *
 */
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

struct Tree
{
    int iV;
    Tree *pL;
    Tree *pR;
  Tree()
  {
      pL = NULL;
      pR=NULL;
      iV=0;
  }
};

class Solution
{
    public:
	//按层序创建二叉树
static Tree * create_fun_1(const vector<int> & vData)
	{
	    Tree *pRoot = new Tree;
	    pRoot->pL =NULL;
	    pRoot->pR = NULL;
	    pRoot->iV= vData[0];
	    queue<Tree*> tQueue;
	    Tree *temp = pRoot;
	    for(int index =1; index < vData.size();++index)
	    {
		int iValue = vData[index];
		if(temp->pL == NULL)
		{
		 temp->pL = new Tree;
		 temp->pL->pR =NULL;
		 temp->pL->pL=NULL;
		 temp->pL->iV = iValue;
		 tQueue.push(temp->pL);
		 continue;
		}
		else if(temp->pR == NULL)
		{
		 temp->pR = new Tree;
		 temp->pR->pR =NULL;
		 temp->pR->pL=NULL;
		 temp->pR->iV = iValue;
		 tQueue.push(temp->pR);
		 continue;
		}
		else
		{
		    temp = tQueue.front();
		    tQueue.pop();
		    --index;
		
		}
	    }
	
		return pRoot;
	}
static void   visit_last_order( Tree* root,vector<int> &vOrder)
{
    stack<Tree*> sTree;
    Tree *tmp = root;
    while( tmp != NULL)
    {
	sTree.push(tmp);
	tmp = tmp->pL;
    }

    while(sTree.size()>0)
    {
	Tree *node = sTree.top();
	sTree.pop();
	if(node->pL == NULL && node->pR==NULL)
	{
	  vOrder.push_back(node->iV);
	}
	else if(node->pR != NULL)
	{
	    visit_last_order(node->pR,vOrder);
	    vOrder.push_back(node->iV);
	}
    }
}

static void   visit_mid_order( Tree* root,vector<int> &vOrder)
{
    stack<Tree*> sTree;
    Tree *tmp = root;
    while( tmp != NULL)
    {
	sTree.push(tmp);
	tmp = tmp->pL;
    }

    while(sTree.size()>0)
    {
	Tree *node = sTree.top();
	sTree.pop();
	if(node->pL == NULL && node->pR==NULL)
	{
	  vOrder.push_back(node->iV);
	}
	else if(node->pR != NULL)
	{
	    vOrder.push_back(node->iV);
	}
	    visit_mid_order(node->pR,vOrder);
    }
}
static void   visit_pre_order( Tree* root,vector<int> &vOrder)
{
    stack<Tree*> sTree;
    Tree *tmp = root;
    vOrder.push_back(tmp->iV);
    if(tmp->pL != NULL)
    {
	visit_pre_order(tmp->pL,vOrder);
    }
    if(tmp->pR != NULL)
    {
	visit_pre_order(tmp->pR,vOrder);
    }
}
static void cout_vector(const vector<int> &vOrder)
{

  for(int index=0;index <vOrder.size();++index)
  {
   cout<<vOrder[index];
  }
  cout<<endl;

}
};
 
int main(char *argv[],int argc )
{
    vector<int> vData={1,2,3,4,5,6,7,8,9};
  Tree *pTree = Solution::create_fun_1(vData);
  vector<int> vOrder;
  Solution::visit_last_order(pTree,vOrder);
  Solution::cout_vector(vOrder);
  vOrder.clear();
  Solution::visit_mid_order(pTree,vOrder);
  Solution::cout_vector(vOrder);
  vOrder.clear();
  Solution::visit_pre_order(pTree,vOrder);
  Solution::cout_vector(vOrder);
  vOrder.clear();

return 0;
}


