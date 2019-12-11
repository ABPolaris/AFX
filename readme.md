# AFX Project #

项目文档ver1.01

程序设计实验课大作业=。=决定版

A代表我（AkiPolaris），F是我搭档的姓，X代表未定的进制。

## 开发目的 #

~~ 完成作业 ~~

实现2^10-1/999/FF以内的，2/10/16进制的正数的四则运算；

运行程序时出现选择进制、做题历史查询、查看帮助的提示；

一组题目7题，每题2次作答机会，每组题目作答完成后显示做题情况，同时选择下一组题目的进制或退出；

实现异常数据（主要是输入）处理；

实现正确、错误题目数量统计；

实现记录做题历史情况；

每做完5005题重置一次记录；

内置简单的帮助界面；

## 迫真UI（部分） #

### 主菜单 #

请选择所需功能

1.2进制出题

2.10进制出题

3.16进制出题

0.帮助

q.退出

### 出题界面 #

（题面）

请输入你的答案：

## 核心函数（F负责） #

int InputNumber(string);（处理回答输入）

其余由F定义

## 配套函数（A负责） #

int main();

int InputChoice(string); （处理非回答输入）

bool RecordResult(int currectScale,int trueAnswer);（记录某进制下回答正确的数量）

bool InquireResult();（查询历史答题情况）

bool CreateResultFile();（答题记录文件初始化）

bool RefreshResultFile();（答题记录文件重建）

bool ScreenHelp();（显示帮助界面）

bool ScreenMenu();（主菜单）