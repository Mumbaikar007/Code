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
        "SPOJ/TETRA - Sphere in a tetrahedron(SPOJ-16).cpp" "Cracking the Coding Interview/Array and Strings/Q1-2A.cpp.cpp" "Cracking the Coding Interview/Array and Strings/Q1-2B.cpp" "Cracking the Coding Interview/Array and Strings/Q1-3.cpp" "Cracking the Coding Interview/Array and Strings/Q1-4.cpp" "CodeChef/Novermber Challenge 2017/VILTRIBE.cpp" "CodeChef/Novermber Challenge 2017/CLRL.cpp" "CodeChef/Novermber Challenge 2017/PERPALIN.cpp" "Cracking the Coding Interview/Array and Strings/Q1-5.cpp.cpp" "Cracking the Coding Interview/Array and Strings/Q1-6.cpp" "Cracking the Coding Interview/Array and Strings/Q1-7.cpp" "Cracking the Coding Interview/Array and Strings/Q1-8.cpp" "Cracking the Coding Interview/Array and Strings/Q1-9.cpp" "Cracking the Coding Interview/Linked List/Q2-1.cpp" "Cracking the Coding Interview/Linked List/LinkedListBaasics.c" "Cracking the Coding Interview/Stacks/Q3-1.cpp" "Cracking the Coding Interview/Stacks/Q3-2.cpp" "Cracking the Coding Interview/Linked List/Experiment.cpp" "Cracking the Coding Interview/Linked List/InsertIntoLL.cpp" "Cracking the Coding Interview/Linked List/Q1-2.cpp" "Cracking the Coding Interview/Linked List/Q1-3.cpp" "Cracking the Coding Interview/Linked List/Q2-6.cpp" "Cracking the Coding Interview/Stacks/Q3-4.cpp" "Cracking the Coding Interview/Stacks/Q3-5.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-1.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-2.cpp" "Cracking the Coding Interview/Trees and graphs/Tree Practice.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-3.cpp" "Cracking the Coding Interview/Trees and graphs/ReadyTree.cpp" "Cracking the Coding Interview/Trees and graphs/Q4-4.cpp" "CodeChef/December Challenge 2017/GIT01.cpp" "CodeChef/December Challenge 2017/CPLAY.cpp" "Cracking the Coding Interview/Bit Manipulation/Q5-1.cpp" "Cracking the Coding Interview/Bit Manipulation/Q5-3.cpp" "CodeForces/DFS/E. Bear and Forgotten Tree 2.cpp" CodeForces/DFS/VariationOne.cpp CodeForces/DFS/Test.cpp "CodeForces/BFS/Cycle In Maze.cpp" "CodeForces/BFS/Police Station.cpp" "HackerRank/ Real Estate Broker .cpp" "Cracking the Coding Interview/Bit Manipulation/Q5-4.cpp" "Cracking the Coding Interview/Bit Manipulation/Q5-7.cpp" "Cracking the Coding Interview/Recursion and Dynamic/Q8-1.cpp" "CodeForces/Djikstra/ Complete The Graph.cpp" CodeForces/Djikstra/Test.cpp "Cracking the Coding Interview/Recursion and Dynamic/Q8-2.cpp" "Hitchhiker's /MaxSumOnALine.cpp" "HackerEarth/Dynamic/Counting Number of Ways .cpp" HackerEarth/Dynamic/On^2.cpp "CodeChef/January Challenge 2018/RECTANGL.cpp" "CodeChef/January Challenge 2018/MAXSC.cpp" "CodeChef/January Challenge 2018/KCON.cpp" CodeChef/ALTARAY.cpp "CodeChef/January Challenge 2018/STRMRG.cpp" "Logics/Arduino's map.cpp" "CodeChef/January Challenge 2018/KCON2.cpp" CodeChef/Practice/DELISH.cpp "SPOJ/HOTELS - Hotels Along the Croatian Coast.cpp" "CodeChef/Practice/DBOY .cpp" Logics/EyantraScan1.cpp "UVA online judge/1.3.3/UVa 00272.cpp" "UVA online judge/1.3.3/UVa 00621.cpp" "UVA online judge/1.3.3/UVa 00119.cpp" Logics/trial.cpp "UVA online judge/1.3.3/UVa 00573.cpp" "UVA online judge/2.2.4/UVa 00230 - Borrowers.cpp" "UVA online judge/3.5.2/507 - Jill Rides Again.cpp" Logics/AsseblerPass1.cpp "UVA online judge/3.5.2/UVa 108 - Maximum Sum.cpp" "Hitchhiker's /LIS.cpp" Logics/StructConstructor.cpp "UVA online judge/3.5.2/147 - Dollars.cpp" HackerRank/EqualTest.cpp "UVA online judge/3.5.2/562 - Dividing coins.cpp")

add_executable(Code ${SOURCE_FILES})

add_executable(single_file_exe "UVA online judge/3.5.2/562 - Dividing coins.cpp")
set_target_properties(single_file_exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/UVA online judge/3.5.2/")
