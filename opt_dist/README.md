
## Optimal Load Distribution

### Description
A computer company wants to transfer K electronic components with bk and wk(weight and value respectively) from area A to area B. In particular, the total weight of the load should not exceed B. The goal is for the company to find the optimal distribution of load that maximizes its total value. We solve this problem using Dynamic Programming.



### Problem configuration
Determination of optimal control problem with load value criterion

    Statutory Equation: 𝒙(𝒌 + 𝟏) = 𝒙(𝒌) + 𝒖(𝒌) ∙ 𝒃𝒌, 𝒙(𝟎) = 𝟎

    Restrictions: 𝒖(𝒌) ∈ {𝟎,𝟏,𝟐,…}, 𝟎 ≤ 𝒙(𝒌) ≤ 𝑩

    Cargo Value Criterion:  𝑱 = ∑ 𝒖(𝒌) ∙ 𝒘𝒌


### Program configuration
    Input parameters
        1. The number of products K
        2. The total weight of cargo B
        3. The weight wk and the value bk of each component

### Compile and Run
    gcc -Wall -o main.c
    ./main.o
