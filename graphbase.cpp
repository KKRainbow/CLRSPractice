/*************************************************************************
    > File Name: graphbase.cpp
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Wed 23 Jul 2014 06:08:03 PM CST
 ************************************************************************/

#include"graphbase.h"
GraphBase::GraphBase()
{

}
bool GraphBase::isDirected()
{
	return bIsDirected;
}
int GraphBase::getVertexNum()
{
	return (int)iVertexNum;
}
