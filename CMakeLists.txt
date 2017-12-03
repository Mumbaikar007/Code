cmake_minimum_required(VERSION 3.8)
project(Code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        "CLRS/Dynamic Programming/Cut-Rod-Problem-Memorization-Top-Down.cpp"
        "CLRS/Dynamic Programming/Cut-Rod-Problem-Recursive-Top-Down.cpp"
        "CLRS/Dynamic Programming/FibonacciDynamic.cpp"
        "CLRS/Dynamic Programming/LongestCommonSubsequence.cpp"
        "CLRS/Dynamic Programming/MatrixChainOrder.cpp"
        CodeChef/CHEFSUM.cpp
        CodeChef/CIELAB.cpp
        CodeChef/CIELRCPT.cpp
        CodeChef/FCTRL.cpp
        CodeChef/FLOW001.cpp
        CodeChef/FLOW002.cpp
        CodeChef/FLOW004.cpp
        CodeChef/FLOW006.cpp
        CodeChef/FLOW007.cpp
        CodeChef/FLOW017.cpp
        CodeChef/FLOW018.cpp
        CodeChef/FSQRT.cpp
        CodeChef/LUCKFOUR.cpp
        CodeChef/MINPERM.cpp
        CodeChef/RAINBOWA.cpp
        CodeChef/RAINBOWA2.cpp
        CodeChef/REMISS.cpp
        CodeChef/START01.cpp
        CodeChef/SUMTRIAN.cpp
        CodeChef/TLG.cpp
        "Cracking the Coding Interview/Array and Strings/Q1-1.cpp"
        "Cracking the Coding Interview/Array and Strings/Q1-1BIN.cpp"
        "HackerEarth/Choosing the judges.cpp"
        HackerEarth/Factorial.cpp
        "HackerEarth/Intelligent Girl.cpp"
        HackerRank/ClimbingLeaderboard.cpp
        HackerRank/eruptingVolcanos.cpp
        HackerRank/MagicSquare.cpp
        "HackerRank/Picking Numbers.cpp"
        "HackerRank/Weighted UniformSubstrings.cpp"
        "Hitchhiker's /LongestCommonSubsequence.cpp"
        "Hitchhiker's /SampleProblemCombinatorics.cpp"
        Logics/CallByReference.cpp
        Logics/Combinations.cpp
        Logics/HardCodeMatrix.cpp
        Logics/PowerSet.cpp
        Logics/string.cpp
        "ProjectEuler/10-Summation of primes.cpp"
        "ProjectEuler/11-Largest product in a grid.cpp"
        "ProjectEuler/12-Highly divisible triangular number.cpp"
        "ProjectEuler/13-Large sum.cpp"
        "ProjectEuler/14 - Longest Collatz sequence.cpp"
        "ProjectEuler/15-Lattice paths.cpp"
        "ProjectEuler/16-Power digit sum.cpp"
        "ProjectEuler/18-Maximum path sum I.cpp"
        "ProjectEuler/20-Factorial digit sum.cpp"
        "ProjectEuler/21-Amicable numbers.cpp"
        "ProjectEuler/22-Names scores.cpp"
        "ProjectEuler/23-Non-abundant sums.cpp"
        "ProjectEuler/25-1000-digit Fibonacci number.cpp"
        "ProjectEuler/8-Largest product in a series.cpp"
        "ProjectEuler/9-Special Pythagorean triplet.cpp"
        "SPOJ/ACPC10A - What’s Next(SPOJ-7974).cpp"
        "SPOJ/ADDREV - Adding Reversed Numbers(SPOJ-42).cpp"
        "SPOJ/FCTRL - Factorial (SPOJ-11).cpp"
        "SPOJ/FCTRL2 - Small factorials(SPOJ-24).cpp"
        "SPOJ/NSTEPS - Number Steps (SPOJ-1112 ).cpp"
        "SPOJ/SAMER08F - Feynman(SPOJ-3410).cpp"
        "SPOJ/TETRA - Sphere in a tetrahedron(SPOJ-16).cpp" "Cracking the Coding Interview/Array and Strings/Q1-2A.cpp.cpp" "Cracking the Coding Interview/Array and Strings/Q1-2B.cpp" "Cracking the Coding Interview/Array and Strings/Q1-3.cpp" "Cracking the Coding Interview/Array and Strings/Q1-4.cpp" "CodeChef/Novermber Challenge 2017/VILTRIBE.cpp" "CodeChef/Novermber Challenge 2017/CLRL.cpp" "CodeChef/Novermber Challenge 2017/PERPALIN.cpp" "Cracking the Coding Interview/Array and Strings/Q1-5.cpp.cpp" "Cracking the Coding Interview/Array and Strings/Q1-6.cpp" "Cracking the Coding Interview/Array and Strings/Q1-7.cpp" "Cracking the Coding Interview/Array and Strings/Q1-8.cpp" "Cracking the Coding Interview/Array and Strings/Q1-9.cpp" "Cracking the Coding Interview/Linked List/Q2-1.cpp" "Cracking the Coding Interview/Linked List/LinkedListBaasics.c" "Cracking the Coding Interview/Stacks/Q3-1.cpp" "Cracking the Coding Interview/Stacks/Q3-2.cpp" "Cracking the Coding Interview/Linked List/Experiment.cpp" "Cracking the Coding Interview/Linked List/InsertIntoLL.cpp" "Cracking the Coding Interview/Linked List/Q1-2.cpp" "Cracking the Coding Interview/Linked List/Q1-3.cpp" "Cracking the Coding Interview/Linked List/Q2-6.cpp" "Cracking the Coding Interview/Stacks/Q3-4.cpp" "Cracking the Coding Interview/Stacks/Q3-5.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-1.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-2.cpp" "Cracking the Coding Interview/Trees and graphs/Tree Practice.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-3.cpp" "Cracking the Coding Interview/Trees and graphs/ReadyTree.cpp" "HackerRank/Floyd : City of Blinding Lights.cpp")

add_executable(Code ${SOURCE_FILES})

add_executable(single_file_exe "HackerRank/Floyd : City of Blinding Lights.cpp")
set_target_properties(single_file_exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/HackerRank/")
