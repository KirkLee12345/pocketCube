# 查找二阶魔方一种可能解的程序

该程序及说明的更新日期：2024-01-20

## 使用方法
### 输入魔方状态
使用一个字符来代表一个颜色，例如```'r'```代表红色。当然，您也可以用其他任意字符来表示颜色。

当程序开始运行时，会进行六次询问，分别询问6个面的状态。

**请注意：每个面有四个色块，输入时的顺序为 左上-右上-右下-左下**

*六个询问输入只是提示，所以您也可以直接把所有状态一次性的复制粘贴输入，然后回车就好了。*

*在输入时也不是一定要在字符间加入空格，例如```rrwb```和```r r w b```效果是一样的。*

**请注意：在输入每个面的状态时，您应该严格按照以下规则翻转到对应面来进行输入：**

*在**前4条**输入中，您都**不需要**移动或者转动魔方。您可以将魔方放在桌面上来观察并输入。*

1. 魔方的正面对着自己，此时正对自己的面是**前面**即**F面**。此时按照**左上-右上-右下-左下**的顺序输入状态。

2. 看向魔方的**上面**，即**U面**。此时按照**左上-右上-右下-左下**的顺序输入状态。

3. 将您的**眼睛**稍微向**右边**移动一小段距离，并看向魔方，此时您能看到的面是**右面**即**R面**。此时按照**左上-右上-右下-左下**的顺序输入状态。输入完毕记得将您的眼睛移动回正中间。

4. 与第3条相似，将您的**眼睛**稍微向**左边**移动一小段距离，并看向魔方，此时您能看到的面是**左面**即**L面**。此时按照**左上-右上-右下-左下**的顺序输入状态。输入完毕记得将您的眼睛移动回正中间。

5. 从这一步开始您可能需要转动魔方才能方便的观察并完成输入。将魔方**向您的方向**滚动**两个面**，如果您在桌面上操作，这看起来会像是魔方在向您滚过来。此时正对自己的面是**后面**即**B面**。此时按照**左上-右上-右下-左下**的顺序输入状态。

6. 在**第5步的前提**下，模仿第2步，看向魔方的**上面**。此时看到的**“上面”**其实是**下面**即**D面**。此时按照**左上-右上-右下-左下**的顺序输入状态。

7. 六个面都输入完毕，**请一定要记得将魔方翻转回原来朝向自己的状态**。您可以模仿**第5步**中的**滚动魔方**的操作再滚动一次，这样魔方就会回到原来的状态。

   输入全部完成后，按下回车，程序就会开始计算得出魔方的解。

   

   ### 根据输出的结果还原魔方

   如果您了解魔方的公式是如何表达的，那么根据输出的结果还原魔方对您来说是易如反掌，只需要**注意**在本程序中使用**小写字母**来表示**逆时针旋转**。例如```r```其实可以看成```R'```，表示**右面逆时针旋转90度**。

   如果您不了解魔方的公式是如何表达的，也可以参考以下对魔方公式中字母的简要概述：

   ```
   R - 右面
   L - 左面
   U - 上面
   D - 下面
   F - 前面
   B - 后面
   字母后面有撇号'表示方向为逆时针，
   例如 R 表示 右面顺时针旋转90度，而 R' 表示右面逆时针旋转90度。
   请注意：在本程序中使用 小写字母 来表示 逆时针旋转 。
   ```

   这里是一张参考图。

   <img src=".\pocketCube.png" alt="image-20240120194615698" style="zoom:50%;" />

   引用来自[2x2 Beginner Guide - GAN魔方 (gancube.com)](https://www.gancube.com/zh/2x2-beginner-guide/)。

   对魔方感兴趣的小伙伴也可以在这里学习如何还原二阶魔方。

例如程序输出结果为```R R f r f R F u```表示您需要按照以下步骤转动魔方：

```
右面顺时针旋转90度
右面顺时针旋转90度
前面逆时针旋转90度
右面逆时针旋转90度
前面逆时针旋转90度
右面顺时针旋转90度
前面顺时针旋转90度
上面逆时针旋转90度
```

## 程序实现原理

### 算法

目前仍然使用**深度优先搜索（DFS）**算法来实现寻找可能解，利用了**二阶魔方在任意情况下还原所需的步数不超过14步的原理**。

遍历旋转顺序为{'R', 'r', 'L', 'l', 'F', 'f', 'B', 'b', 'U', 'u', 'D', 'd'}，因此在程序找到的可能解中RrLlFf可能出现很多次。

## To-Do

更换算法，以求找出二阶魔方还原的**最优解**，并提升程序运行速度，减少计算时间。