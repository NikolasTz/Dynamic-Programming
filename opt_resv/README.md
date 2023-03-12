
## Optimal Reservation Policy

### Description

The problem is to find the optimal reservation policy for an airline company that maximizes the company's revenue for each flight. The optimal reservation policy should consider the following parameters:

1. The capacity **X** of the airplane
2. The policy should be planned **K hours** before the flight
3. The number of reservations per hour
4. The number of canceled reservations
5. The cost of a ticket refund

### Problem configuration

    Statutory Equation: 𝒙(𝒌 + 𝟏) = 𝒙(𝒌) − 𝒛(𝒌) + 𝒎𝒊𝒏{𝒖(𝒌), 𝒅(𝒌)}

     𝒙(𝒌): The number of reservation in the kth hour
     𝒛(𝒌): The number of the reservation during the kth hour. We assume that is a discrete stochastic random variable following the uniform distribution, P[z(k)]
     𝒖(𝒌): The maximum number of new reservations to be accepted during the k-th hour, 0 ≤ 𝒖(𝒌) ≤ 𝒎𝒊𝒏{𝑫, 𝝀𝜲 − 𝒙(𝒌)} with 𝝀 ∈ ℤ , 𝒖(𝒌) ∈ [𝟎, 𝑫]
     𝒅(𝒌): The number of requested reservations during the k-th hour. We assume that is a discrete stochastic random variable following the uniform distribution, P[d(k)], 𝒅(𝒌) ∈ [𝟎, 𝑫]

```
Objective cost criterion    

𝑱 = 𝒗 ∗ 𝒎𝒊𝒏{𝒙(𝒌),𝑿} − 𝝁 ∗ 𝒎𝒂𝒙{𝟎, 𝒙(𝒌) − 𝑿}

The cost criterion refers to the company’s revenue during one flight, given the 𝒙(𝒌) and 𝜿. 
The first term refers to the company’s revenue from the sale of tickets with a value of v. 
The second term refers to the total amount of refunds for each customer who does not have a seat available on the airplane. We assume that the ticket refund is μ.

```

### Program configuration
    Input parameters
        1. The capacity X of the airplane
        2. The number of hours K
        3. The upper bound D for the uniform distributions d,u
        4. The parameter λ that defines the upper bound of the new reservations
        5. The value of ticket v
        6. The ticket refund μ



### Compile and Run
    gcc -Wall -o main.c
    ./main.o
