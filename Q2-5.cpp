
// dev c++

# include <iostream>
# include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node *next;	
};

Node *InsertTail ( Node *head, int data ){
	
	Node *newNode = ( Node *) malloc (sizeof (Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if ( head == NULL)
		return newNode;
		
	else {
		
		Node *traverse = head;
		while ( traverse->next != NULL)
			traverse = traverse->next;
			
		traverse->next = newNode;
		
	}
	
	return head;
}




Node *SumOfNumbers( Node *result, Node *number1, Node *number2, int count){

	if ( number1 == NULL && number2 == NULL && count == 0)
		return NULL;
		
	int value = count;
	
	if ( number1 != NULL )
		value += number1->data;
		
	if ( number2 != NULL )
		value += number2->data;
		
	result = InsertTail ( result, value % 10);
	
	//cout << value << endl;
	
	count = (value / 10);	
		
	if ( number1 != NULL || number2 != NULL || count != 0 ){
		
		result->next = SumOfNumbers ( result->next, 
							(number1 == NULL) ? NULL : number1->next, 
							(number2 == NULL) ? NULL : number2->next, 
							count );
	}
	
	return result;
}



int main(){
	
	Node *number1 = NULL, *number2 = NULL;
	
	number1 = InsertTail ( number1, 7);
	number1 = InsertTail ( number1, 1);
	number1 = InsertTail ( number1, 6);
	
	number2 = InsertTail ( number2, 5);
	number2 = InsertTail ( number2, 9);
	number2 = InsertTail ( number2, 2);
	
	
	Node *traverse = number1;
	
	while ( traverse != NULL ){
		std::cout << traverse->data; 
		traverse = traverse->next;
	}
	
	traverse = number2;
	
	while ( traverse != NULL ){
		std::cout << traverse->data; 
		traverse = traverse->next;
	}
	
	cout << endl;
	
	Node *result = NULL;
	result = SumOfNumbers( result, number1, number2, 0);
	
	
	
	traverse = result;
	
	while ( traverse != NULL ){
		std::cout << traverse->data; 
		traverse = traverse->next;
	}
		
	//cout << SumOfNumbers( number1, number2 ) << endl;
	
	return 0;
}
