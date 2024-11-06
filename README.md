# Parallel Merge Sort

## Overview

This project demonstrates a **Parallel Merge Sort** algorithm using **multithreading** to improve sorting performance for large datasets.

## Prerequisites

- **Linux-based operating system** (e.g., Ubuntu) **As Vscode doesnt support thread**
- **g++ compiler**

## Setup Instructions

1. **Clone the repository:**

   ```bash
   git clone https://github.com/karthikrk0180/Multithreaded-Merge-Sort.git
   cd Multithreaded-Merge-Sort/src/app

2. **Compiple the project**

   ```bash
   g++ -std=c++11 -o parallel_sort main.cpp sorting/mergesort.cpp sorting/parallelMergeSort.cpp -pthread


3. **Run the program:**

   ```bash
   ./parallel_sort

   

