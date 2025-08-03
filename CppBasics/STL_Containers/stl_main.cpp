#include <iostream>
#include <iomanip>
#include <limits>

// Include only STL containers header
#include "12_STL_Containers.h"

using namespace CppBasics;

void printSeparator() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
}

void printHeader(const std::string& title) {
    printSeparator();
    std::cout << "           " << title << std::endl;
    printSeparator();
}

void displaySTLMenu() {
    std::cout << "\n=== STL CONTAINERS & ALGORITHMS DEMONSTRATION ===" << std::endl;
    std::cout << "\nChoose what to explore:" << std::endl;
    
    std::cout << "\n[CONTAINERS]:" << std::endl;
    std::cout << "1. All STL Containers Demo" << std::endl;
    std::cout << "2. Container Performance Comparison" << std::endl;
    std::cout << "3. Container Selection Guide" << std::endl;
    
    std::cout << "\n[ALGORITHMS]:" << std::endl;
    std::cout << "4. All STL Algorithms Demo" << std::endl;
    std::cout << "5. Algorithm Performance Analysis" << std::endl;
    
    std::cout << "\n[ITERATORS]:" << std::endl;
    std::cout << "6. All Iterator Demonstrations" << std::endl;
    std::cout << "7. Custom Iterator Examples" << std::endl;
    
    std::cout << "\n[INTERVIEW PREP]:" << std::endl;
    std::cout << "8. Common Interview Problems" << std::endl;
    std::cout << "9. STL Best Practices" << std::endl;
    
    std::cout << "\n[COMPREHENSIVE]:" << std::endl;
    std::cout << "10. Complete STL Mastery Tour" << std::endl;
    
    std::cout << "\n0. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
}

void runContainersDemo() {
    printHeader("STL CONTAINERS COMPREHENSIVE DEMO");
    std::cout << "\n* Demonstrating all STL container types!" << std::endl;
    STLContainersDemo::demonstrateAll();
}

void runAlgorithmsDemo() {
    printHeader("STL ALGORITHMS COMPREHENSIVE DEMO");
    std::cout << "\n Demonstrating STL algorithms mastery!" << std::endl;
    STLAlgorithmsDemo::demonstrateAll();
}

void runIteratorsDemo() {
    printHeader("STL ITERATORS COMPREHENSIVE DEMO");
    std::cout << "\n* Demonstrating iterator categories and usage!" << std::endl;
    STLIteratorsDemo::demonstrateAll();
}

void runInterviewQuestionsDemo() {
    printHeader("STL INTERVIEW QUESTIONS");
    std::cout << "\n* Common STL questions asked in technical interviews!" << std::endl;
    STLInterviewQuestions::demonstrateAll();
}

void runBestPracticesDemo() {
    printHeader("STL BEST PRACTICES");
    std::cout << "\n* Professional guidelines for STL usage!" << std::endl;
    STLBestPractices::demonstrateAll();
}

void runCompleteSTLTour() {
    printHeader("*** COMPLETE STL MASTERY TOUR ***");
    std::cout << "\n* This comprehensive tour covers EVERYTHING about STL!" << std::endl;
    std::cout << "Perfect for mastering STL for technical interviews!" << std::endl;
    
    std::cout << "\n=== PART 1: CONTAINERS ===\n";
    std::cout << "Press Enter to start containers demonstration...";
    std::cin.get();
    runContainersDemo();
    
    std::cout << "\n=== PART 2: ALGORITHMS ===\n";
    std::cout << "Press Enter to continue to algorithms...";
    std::cin.get();
    runAlgorithmsDemo();
    
    std::cout << "\n=== PART 3: ITERATORS ===\n";
    std::cout << "Press Enter to continue to iterators...";
    std::cin.get();
    runIteratorsDemo();
    
    std::cout << "\n=== PART 4: INTERVIEW PREPARATION ===\n";
    std::cout << "Press Enter to continue to interview questions...";
    std::cin.get();
    runInterviewQuestionsDemo();
    
    std::cout << "\n=== PART 5: BEST PRACTICES ===\n";
    std::cout << "Press Enter to continue to best practices...";
    std::cin.get();
    runBestPracticesDemo();
    
    printHeader("*** STL MASTERY ACHIEVED! ***");
    std::cout << "*** CONGRATULATIONS! ***" << std::endl;
    std::cout << "You have successfully mastered STL containers and algorithms!" << std::endl;
    std::cout << "\n* What you've learned:" << std::endl;
    std::cout << "* All STL container types and their use cases" << std::endl;
    std::cout << "* Complete algorithm library mastery" << std::endl;
    std::cout << "* Iterator categories and custom implementations" << std::endl;
    std::cout << "* Common interview problems and solutions" << std::endl;
    std::cout << "* Professional best practices and optimization tips" << std::endl;
    std::cout << "\n*** You're now ready for any STL-related interview questions! ***" << std::endl;
}

int main() {
    std::cout << "*** Welcome to STL Containers & Algorithms Mastery! ***" << std::endl;
    std::cout << "The most comprehensive STL learning and interview preparation tool!" << std::endl;
    std::cout << "\nThis focused program covers:" << std::endl;
    std::cout << "* All STL containers with performance analysis" << std::endl;
    std::cout << "* Complete algorithm library with examples" << std::endl;
    std::cout << "* Iterator categories and custom implementations" << std::endl;
    std::cout << "* Common interview problems and solutions" << std::endl;
    std::cout << "* Professional best practices and optimization tips" << std::endl;
    
    int choice;
    
    do {
        displaySTLMenu();
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                runContainersDemo();
                break;
            case 2:
                printHeader("CONTAINER PERFORMANCE COMPARISON");
                STLContainersDemo::performanceTest();
                break;
            case 3:
                printHeader("CONTAINER SELECTION GUIDE");
                STLContainersDemo::demonstrateContainerChoice();
                break;
            case 4:
                runAlgorithmsDemo();
                break;
            case 5:
                printHeader("ALGORITHM PERFORMANCE ANALYSIS");
                std::cout << "* Algorithm performance characteristics and optimization tips\n";
                STLAlgorithmsDemo::demonstrateTransformOperations();
                STLAlgorithmsDemo::demonstrateNumericOperations();
                break;
            case 6:
                runIteratorsDemo();
                break;
            case 7:
                printHeader("CUSTOM ITERATOR EXAMPLES");
                STLIteratorsDemo::demonstrateCustomIterators();
                break;
            case 8:
                runInterviewQuestionsDemo();
                break;
            case 9:
                runBestPracticesDemo();
                break;
            case 10:
                runCompleteSTLTour();
                break;
            case 0:
                std::cout << "\nThank you for exploring STL mastery!" << std::endl;
                std::cout << "You now have the knowledge to excel in any C++ technical interview!" << std::endl;
                std::cout << "Keep practicing and happy coding!" << std::endl;
                break;
            default:
                std::cout << "\nERROR: Invalid choice! Please try again." << std::endl;
                break;
        }
        
        if (choice != 0 && choice != 10) {
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
} 
