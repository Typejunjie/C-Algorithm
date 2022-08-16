# 王道计算机考研应用题

> 如果已经安装git可以以以下方式克隆到本地

```cmd
git clone https://github.com/Typejunjie/C-Algotithm.git
```

## 如何在本地运行算法

### 示例

```cpp
#include "algorithm-graph/TopologicalSorting.h"              // 引入算法所在头文件
using namespace std;

int main()
{
    directionGraph G;                                        // 声名结构体
    int pointArr[] = {1, 2, 3, 4, 5};                        // 定义适当传参
    int edgeArr[][3] = {2, 1, 2, 3, 1, 3, 4, 1, 4, 5, 4, 5};
    createDirectionGraph(G, pointArr, 5, edgeArr, 4);        // 创建数据结构
    topologicalSorting(G);                                   // 执行算法
}
```

## 目录

### 线性表

- [顺序存储定义及基本方法](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/linearList.h)
- [链表定义及基本方法](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/linkList.h)
- [循环双链表定义及基本方法](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/dualCircleList.h)
- [双链表定义及基本方法](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-special/dualLinkListAndFreq.h)
- [实现locale函数](https://github.com/Typejunjie/C-Algotithm/blob/main/linearList/algorithm-special/dualLinkListAndFreq.h)
- [查找主元素（占据半数）](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/findMainNum.h)
- [求两个有序序列的中位数](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/findMidNum.h)
- [求未出现的最小正整数(不包括0)](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/findMinNum.h)
- [计算所有可能三元组中距离小值](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/mergeList.h)
- [将一个整数数组的所有元素一致右移p个单位](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/moveElement.h)
- [二分查找元素key，找到则将其与后继元素交换](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Linear/searchOper.h)
- [将后面一半的元素倒置插入到前一半结点中间位置](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/buildMixList.h)
- [去掉绝对值相同的结点](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/deleteAbsSim.h)
- [删除值为x的结点](https://github.com/Typejunjie/C-Algorithem/blob/main/linearList/algorithm-Link/deleteEle.h)
- [删除给定范围内的值的结点](https://github.com/Typejunjie/C-Algorithem/blob/main/linearList/algorithm-Link/deleteInSpenNum.h)
- [删除最小值结点](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/deleteMinNum.h)
- [去重](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/deleteSim.h)
- [找到链表中倒数第x个元素并输出](https://github.com/Typejunjie/C-Algotithm/blob/main/linearList/algorithm-Link/findCountBackwordX.h)
- [找到公共后缀起始位置](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/findPublicSuffix.h)
- [找出两个单链表中相同的结点](https://github.com/Typejunjie/C-Algotithm/blob/main/linearList/algorithm-Link/findSimNode.h)
- [从两个链表中抽取相同结点](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/findSimNodeFromOrder.h)
- [判断链表是否中心对称](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/judgeCenterSymmetry.h)
- [判断一个单链表是否有环](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/jadgeCircle.h)
- [判断是否为子序列](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/jadgeSubsequence.h)
- [合并两个有序链表](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/mergeListInReverse.h)
- [使链表递增有序](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/orderlyList.h)
- [递增次序输出单链表的结点](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/outputInOrder.h)
- [将单链表就地逆置](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/reverseList.h)
- [反向打印链表](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/reverseLog.h)
- [将链表分为偶数与奇数两个链表](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/splitList.h)
- [将一个单链表中奇数位置与偶数位置元素拆分为两个单链表](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-Link/splitListInharf.h)
- [循环找出最小结点并删除，直到为空链表再删除头结点](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-circleList/findMinNodeAndDele.h)
- [判断链表是否对称](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-circleList/jadgeSymmetry.h)
- [合并两个循环双链表](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-circleList/mergeCircleList.h)

### 树

- [树的定义](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/interfere.h)
- [在已经建成的二叉树条件下线索化](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/createClueTree.h)
- [打印值为x的元素的所有祖先](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/LogXancestors.h)
- [求树的宽度，即结点数最多的一层结点个数](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/TreeWith.h)
- [树的层次遍历](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/arrangementLog.h)
- [计算孩子兄弟表示法存储的森林的叶子结点数](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/countForestLeaf.h)
- [计算一颗以孩子兄弟存储法存储的树的深度](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/countTreeDepth.h)
- [计算双分支结点个数](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/countTwoBranch.h)
- [计算WPL](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/countWPL.h)
- [根据先序和中序构建二叉链表存储的二叉树](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/createTreeINPre.h)
- [删去值为x的结点的子树](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/deleteXTreeSson.h)
- [交换所有左右子树的值](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/exchangeLRnode.h)
- [找到两个结点的最近公共祖先](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/findAncestors.h)
- [找到先序遍历中第k个元素](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/findXpointInPre.h)
- [依据层次遍历和结点的度构造孩子兄弟存储的树](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/fromArrangeAndDegreeToTree.h)
- [由满二叉树的先序序列求出其后序序列](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/fullTreePreToPost.h)
- [给定在中序线索二叉树的结点，找其后序遍历前驱](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/inClueTreeXInPostPrior.h)
- [由表达式二叉树构造适当括号的中缀表达式](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/inLogMinSuffic.h)
- [判断树的层数](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/jadgeDepth.h)
- [判断二叉树是否为完全二叉树](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/jadgeTreeComplete.h)
- [判断两颗树是否相似](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/jadgeTreeSimilar.h)
- [将叶子结点从左到右链接为一个单链表](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/linkLeaf.h)
- [非递归实现后续遍历](https://github.com/Typejunjie/C-Algorithm/blob/main/tree/algorithm-Tree/postLogTreeInNoRecursion.h)

### 串

- [串的定义及BF算法](https://github.com/Typejunjie/C-Algorithm/blob/main/String/string.h)

### 栈

- [链栈](https://github.com/Typejunjie/C-Algorithm/blob/main/Stack/linkStack.h)
- [线栈](https://github.com/Typejunjie/C-Algorithm/blob/main/Stack/linearStack.h)
- [共享栈](https://github.com/Typejunjie/C-Algorithm/blob/main/Stack/shareStack.h)
- [括号匹配](https://github.com/Typejunjie/C-Algorithm/blob/main/Stack/algorithm-linearStack/jadgeMatching.h)
- [算法：递归函数的非递归实现
        { 1  ,n = 0
Pn(x) = { 2x ,n = 1
        { 2xPn-1(x) - 2(n - 1)Pn-2(x) ,n > 1](https://github.com/Typejunjie/C-Algorithm/blob/main/Stack/algorithm-linearStack/recursiveFun.h)

### 队列

- [线性队列](https://github.com/Typejunjie/C-Algorithm/blob/main/Queue/linearQueue.h)

### 图

- [邻接表存储图](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-linklist.h)
- [邻接矩阵存储图](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-matrix.h)
- [有向带权网的定义及创建（邻接矩阵存储）](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-direction-weightedEdge.h)
- [判断是否存在El路径](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/algorithm-graph/jadgeElRoute.h)
- [将邻接表转为邻接矩阵](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/algorithm-graph/transGFromLinkToMatrix.h)
- [DFS-邻接表](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-linklist.h)
- [BFS-邻接表](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-linklist.h)
- [DFS-邻接矩阵](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-matrix.h)
- [BFS-邻接矩阵](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/graph-matrix.h)
- [判断图是否是一颗树](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/algorithm-graph/judgeTree.h)
- [判断图中两结点是否存在路径](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/algorithm-graph/judgementPath.h)
- [拓扑排序](https://github.com/Typejunjie/C-Algorithm/blob/main/Graph/algorithm-graph/TopologicalSorting.h)

### 查找

- [折半查找](https://github.com/Typejunjie/C-Algotithm/blob/main/linearList/algorithm-linear/Half-foldlookup.h)

### 排序

- [选择排序（基于顺序存储）](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-insertOrder/insterOrder.h)
- [直接插入排序](https://github.com/Typejunjie/C-Algorithm/blob/main/linearList/algorithm-insertOrder/insterOrder.h)
- [简单选择排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)
- [快速排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)
- [冒泡排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)
- [希尔排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)
- [折半插入排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)
- [直接插入排序](https://github.com/Typejunjie/C-Algorithm/blob/main/sort/operate.h)

### 写在最后

>没有人是为了考研而考研的，或多或少都是为了梦想、理想、愿望
