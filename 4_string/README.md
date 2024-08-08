## 字符串

1. 反转字符串(343)  
1 两两交换(使用第三个容器)  
1 位运算  
2. 反转字符串2(541)
3. [替换数字](https://kamacoder.com/problempage.php?pid=1064)
4. 翻转字符串里的单词(151)  
5_leftRevolve左旋字符串
5. [右旋字符串](https://kamacoder.com/problempage.php?pid=1065)
6. 实现strStr(28)(前缀表、KMP算法)(find方法)
7. 重复的子字符串(459)(移动匹配)  
7_重复的子字符串(459)(KMP算法)(尚未理解)

## 1 两两交换(使用第三个容器)  
```
void (char&a, char&b){
    char tmp = a;
    a = b;
    b = tmp;
}
```

## 2 反转字符串2(541)
```
void reverse(string &s, int begin, int end){}
```

## 3 替换数字
1. 旧字符串的下标sOldIndex
2. 计算数字的数量
3. 重新调整字符串的长度
4. 新字符串的下标sNewIndex
5. while(sOldIndex>=0){}
```
while(sOldIndex>=0){
    if(s[sOldIndex]>='0' && s[sOldIndex]<='9'){
        s[sNewIndex--] = ' ';
        ...
    }
    else
    {
        s[sNewIndex--] = s[sOldIndex];
    }
    sOldIndex--;
}
```

## 4 翻转字符串里的单词
1. 去除空格(演示+代码)
```
    f(指针)
_ _ h e l l o
s(指针)

            f(指针)
h e l l o l o
        s(指针)
```
```
// 去除空格
void removeExtraSpaces(string &s){
    // 双指针(快慢指针)
    int slow = 0;
    for(int fast=0; fast<s.size(); fast++){
        if(s[fast] != ' '){
            ...
        }
    }
    // 实质上是覆盖
    while(fast<s.size() && s[fast]!=' '){
        s[slow]=s[fast];
    }
}
```
2. 单词间插空格
```
if(slow != 0){
    s[slow] = ' ';
    slow++;
}
```
3. 🌟重新调整大小
```
s.resize(slow);
```

## 5 右旋字符串
1. abcd ef
2. dcba fe
3. ef abcd

## 6 实现strStr
1. 前缀表(-1版本)
```
void getNext(int *next, const string &s){
    // 初始化
    int j = -1;
    next[0] = j;
    // 从1开始(主函数从0开始)
    for(int i=1; i<s.size(); i++){
        // 注意是while(主函数是haystack和needle)
        while(j>=0 && s[i]!=s[j+1]){
            // 回退
            j = next[j];
        }
        // 最长公共前后缀(主函数是haystack和needle)
        if(s[i]==s[j+1]){
            j++;
        }
        // 填充(主函数是 j==needle.size()-1; return i-needle.size()+1;)
        next[i] = j;
    }
}
```

## 7 重复的子字符串(459)(移动匹配) 
1. string t = s + s;
2. 去头掐尾(erase+注意掐尾时需-1)
```
t.erase(t.end()-1);
```
3. find方法
```
if(t.find(s) != std::string::npos){
    return true;
}
```
