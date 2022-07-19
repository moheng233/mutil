# 大概率很有用功能的封装库


## MPack
```c
MPack* pack = MPack_CreatePack(20);
MPack_PackInt(pack, 10);
MPack_UsartSend(pack, USART2);
```