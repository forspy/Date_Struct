﻿//图：Graph=(V,E);
//V:顶点的有穷非空集合
//E：边的有穷集合
//图分为：有向图和无向图以及完全图（任意两个点都有一条边相连）
//无向完全图有n(n-1)/2条边（n为顶点数）
//有向完全图有n(n-1)条边
/*
其他分类：
稀疏图：有很少边或弧的图。
稠密图：有较多边或弧的图。
网：边/弧带权的图。
邻接：有边/弧相连的两个顶点之间的关系。
(vi,vj）无向图的边 
<vi,vj>有向图的边
存在(vi, vj)，则称vi和vj互为邻接点；
存在<vi, vj>，则称vi邻接到vj， vj邻接于vi
关联(依附)：边/弧与顶点之间的关系。
存在(vi, vj)/ <vi, vj>， 则称该边/弧关联于vi和vj

*/
/*
//梅开二度
顶点的度：与该顶点相关联的边的数目，记为TD(v)
在有向图中, 顶点的度等于该顶点的入度与出度之和。
顶点 v 的入度是以 v 为终点的有向边的条数, 记作 ID(v)
顶点 v 的出度是以 v 为始点的有向边的条数, 记作OD(v)
当有向图中仅1个顶点的入度为0,其余顶点的入度均为1，此时是何形状？
是树！而且是一棵有向树！
*/
/*
无向图中任意两个顶点都是联通的叫连通图
有向图中任意两个顶点都是联通的叫强连通图
*/
/*
路径：接续的边构成的顶点序列。
路径长度：路径上边或弧的数目/权值之和。
回路(环)：第一个顶点和最后一个顶点相同的路径。
简单路径：除路径起点和终点可以相同外，不重复顶点
简单回路(简单环)：除路径起点和终点相同外，其余顶点均不相同的路径。从起点开始回到起点
*/
//在无（有）向图G=( V, {E} )中，若对任何两个顶点 v、u 都存在从v 到 u 的路径，则称G是连通图（强连通图）。
//图中边或弧所具有的相关数称为权（顶点之间的路径长度）。表明从一个顶点到另一个顶点的距离或耗费。带权的图称为网。
//设有两个图G=（V，{E}）、G1=（V1，{E1}），若V1  V，E1  E，则称 G1是G的子图。
/*
无向图G 的极大连通子图称为G的连通分量。极大连通子图意思是：该子图是 G 连通子图，
将G 的任何不在该子图中的顶点加入，子图不再连通。
有向图G 的极大强连通子图称为G的强连通分量。极大强连通子图意思是：该子图是G的强连通子图，
将D的任何不在该子图中的顶点加入，子图不再是强连通的。
*/
/*
极小连通子图：该子图是G 的连通子图，在该子图中删除任何一条边，子图不再连通。
生成树：包含无向图G 所有顶点的极小连通子图。生成森林：对非连通图，由各个连通分量的生成树的集合。
*/
