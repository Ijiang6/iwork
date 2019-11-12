/*
 *
 *创建二叉树
 *
 */
#include<iostream>
#include<queue>
#include<vector>
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
static Tree * fun_1(const vector<int> & vData)
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
		return pRoot;
	    }
	
	}

};
 
int main(char *argv[],int argc )
{
    vector<int> vData={1,2,3,4,5,6,7,8,9};
  Tree *pTree = Solution::fun_1(vData);

return 0;
}


