## myproject

### 设计模式
https://blog.csdn.net/woxiaohahaa/article/details/51344409

### gdb调试
下载gdb脚本 
启动gdb以后，用source stl-views.gdb把脚本包含进来，然后就可以用pmap plist打印内容了

gdb调试时，打印变量的显示No symbol "i" in current context。
在编译是加-gdwarf-3即可，出现这样的原因是gcc,gdb的版本不匹配造成的
