# Bernoulli Distribution Simulator

This is a C program that simulates Bernoulli trials and computes key properties like PMF (probability mass function), expected value, and variance. It also visualizes success and failure rates using a simple text-based histogram.

## What’s a Bernoulli Distribution?

A **Bernoulli distribution** models a random experiment that has exactly two possible outcomes:
- Success (usually represented by `1`)
- Failure (usually represented by `0`)

It’s the most basic discrete probability distribution, and the foundation for binomial and other distributions.

## Binomial Distribution Support

This project also supports the Binomial Distribution, a fundamental probability distribution that models the
number of successes in a fixed number of independent Bernoulli trials, each with the same probability of 
success `p`. The program allows users to calculate the Probability Mass Function (PMF) and the Cumulative 
Distribution Function (CDF) for any valid number of trials `n` and success probability `p`. Additionally, it
can simulate a binomial experiment `k` times, giving insight into the distribution's empirical behavior.

## What This Program Does

- Simulates `n` Bernoulli trials with success probability `p`  
- Prints whether each trial resulted in a success or failure  
- Computes The actual success rate from the simulation  
- Computes Expected value (theory vs empirical)
- Computes Variance (based on simulated distribution)  
- Displays a histogram of successes vs failures  
- Measures execution time  

## Example output

![bern](https://github.com/Brist0l/Stats-Distributions/blob/main/imgs/bern.png)
