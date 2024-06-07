# COP 1334 Assignment - Introduction to C++

## Chapter 6: Challenge 10

## Title: Future Value

### Exercise Description:

Suppose you have a certain amount of money in a savings account that earns compound monthly interest, and you want to calculate the amount that you will have after a specific number of months. The formula, which is known as the future value formula, is
𝐹 = 𝑃 × 1 + 𝑖<sup>𝑡</sup>

The terms in the formula are as follows:

_• F_ is the **future value** of the account after the specified time period.
_• P_ is the **present value** of the account.
_• i_ is the **monthly interest rate**.
_• t_ is the **number of months**.

Write a program that prompts the user to enter the account’s present value, monthly interest rate, and the number of months that the money will be left in the account. The program should pass these values to a function named `futureValue` that returns the future value of the account, after the specified number of months. The program should display the account’s future value.

**Note:**

The Future Value Formula shown on the mandatory Pearson ebook is wrong:

𝐹 = 𝑃 × 1 + 𝑖<sup>𝑡</sup>

That's mathematically equivalent to:

𝐹 = 𝑃 + 𝑖<sup>𝑡</sup>

And that's also **not** the Future Value Formula.

The real Future Value Formula (using Compound interest) is:

𝐹 = 𝑃 × (1 + 𝑖)<sup>𝑡</sup>



## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name


  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


