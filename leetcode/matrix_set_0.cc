/*
 *给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。
 *
 *
 *
 *
 *
 *
 *
 *
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
	static void fun_1(vector<vector<int>>vData)
	{
	    vector<int>vRow;
	    vector<int>vColumn;
	    for(int row =0; row<vData.size();++row)
	    {
		for(int column =0 ;column< vData[row].size();++column)
		{
		 if( vData[row][column] == 0)
		 {
		   vRow.push_back(row);
		   vColumn.push_back(column);
		 }
		}
	    }

	    for(int index =0; index< vRow.size();++index)
	    {
		int row = vRow[index];
                for(int index_2=0 ;index_2 < vData[row].size();++index_2)
		{
		    vData[row][index_2] =0;
		
		}
	    }
	    for(int index =0; index < vColumn.size();++index)
	    {
		int column = vColumn[index];

		for(int index_2 =0; index_2< vData.size();++index_2)
		{
		  vData[index_2][column] =0;
		}
	    }
	    //cout
	 for(int index =0; index <vData.size();++index)
	 {
	   for(int index_2 =0; index_2<vData[index].size();++index_2)
	   {
	   
	     cout<<vData[index][index_2];
	   }
	   cout<<endl;
	 }
	}



};
int main(char *argv[] ,int argc)
{
    vector<vector<int>> vData;
    vector<int> v1={1,2,3};
    vector<int>v2={1,0,3};
    vector<int>v3={3,2,1};
    vData.push_back(v1);
    vData.push_back(v2);
    vData.push_back(v3);
 Solution::fun_1(vData);
return 0;
}
