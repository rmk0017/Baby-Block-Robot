#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

char get_block(void)
{
    char block;
    cout << "Enter one block: ";
    cin >> block;
    return toupper(block);
}
//
// Function print_slots
// Prints the contents of the slots array in a well formatted form.
// Input: Array of slots
// Returns: Nothing (void)
//
// Example function call: print_slots(slot_array);

void print_slots(char slots[])
{
    unsigned int j = 1;
    for (j = 1; j <= 20; j++)
    {
        cout << setw(3) << j;
    }
    cout << endl;
    for (j = 0; j < 20; j++)
    {
        cout << setw(3) << slots[j];
    }
    cout << endl;
}

// Function put_block
// This function stores a character into the character array representing the slots
//
// Inputs:
// block - type char - The character to be inserted into a slot
// position - type unsigned int - index of the slot where the block will go
// array - type char - array of slots containing the blocks
//
// Returns:
// position - type unsigned int - the index of the slot where the block was placed
//
// Example function call: 	put_block(block, position, slots);

unsigned int put_block(char block, unsigned int position, char array[])
{
    bool debug = true;
    array[position] = block;
    if (debug)
        cout << "Block " << block << " inserted into slot " << position << endl;
    return position;
}

// Function remove_block
// This function removes a block from the slot array
// The slot where the block is removed is then set to a space
//
// Inputs:
// position - type unsigned int - index of the slot where block is located
// array - type char - array of slots containing the blocks
//
// Returns:
// block - type char - the block removed from the slot
//
// Example function call: 	remove_block(position, slots);

unsigned int remove_block(unsigned int position, char array[])
{
    bool debug = true;
    char block = ' ';
    block = array[position];
    array[position] = ' ';  // Reset slot to blank after block removed
    if (debug)
        cout << "Block " << block << " removed from slot " << position + 1 << endl;
    return block;
}


// Function shift_right
// This function increments the index simulating a movement of the robot
// to the next higher slot (index) of the array
//
// Inputs:
// position - type unsigned int - current slot position
//
// Returns:
// position - type unsigned int - The updated position which is input position + 1
//
// Example function call:  position = shift_right(position)
//

unsigned int shift_right(unsigned int position)
{
    bool debug = true;
    position++;
    if (debug)
        cout << "Position right shifted to " << position << endl;
    return position;
}

// Function shift_left
// This function decrements the index simulating a movement of the robot
// to the next lower slot (index) of the array
//
// Inputs:
// position - type unsigned int - current slot position
//
// Returns:
// position - type unsigned int - The updated position which is input position - 1
//
// Example function call: position = shift_left(position)
//

unsigned int shift_left(unsigned int position)
{
    bool debug = true;
    position--;
    if (debug)
        cout << "Position left shifted to " << position << endl;
    return position;
}

// Function robot_ltoreq_slot
// This function compares the value of the block held by the robot
// with the value of the block in a slot
//
// Inputs:
// robot - type char - value of block held by robot
// in_slot - type char - value of block in the slot
//
// Returns:
// true or false
// TRUE if block held by robot is LESS than or equal to the block in slot
// FALSE if block held by robot is GREATER than block in slot
//
// Example function call: if ( compare_blocks(robot_block, slot_block) )
//
bool robot_ltoreq_slot(char robot, char in_slot)
{
    bool debug = true;
    if (debug)
        cout << endl <<  "Comparing robot block " << robot << " with block in slot " << in_slot << endl;
    if (robot <= in_slot)
    {
        if (debug)
            cout << "Returning true. Robot block LESS than or EQUAL to block in slot. " << endl;
        return true;
    }
    else
    {
        if (debug)
            cout << "Returning false. Robot block GREATER than block in slot. " << endl;
        return false;
    }
}
// This function checks if the blocks are less than or == to the block in the robots hand
// If the block is equal to it return TRUE if the block is < it return FALSE

bool robot_equal_slot(char robot, char in_slot)
{
    bool debug = true;
    if (debug)
        cout << endl <<  "Comparing robot block " << robot << " with block in slot " << in_slot << endl;
    if (robot == in_slot)
    {
        if (debug)
            cout << "Returning true. Robot block EQUAL to block in slot. " << endl;
        return true;
    }
    else
    {
        if (debug)
            cout << "Returning false. Robot block LESS THAN than block in slot. " << endl;
        return false;
    }
}

// Function switch_blocks
// This function switches the block held by the robot with a block in a slot.
// After the switch the robot is holding the block removed from the slot.
//
// Inputs:
// robot - type char - The block to be inserted into a slot
// position - type unsigned int - index of the slot where the block will go
// array - type char - array of slots containing the blocks
//
// Returns:
// robot - type char. The value of the block removed from the slot.
//
// Example function call: block = switch_blocks(block,  position, array);
//

char switch_blocks(char robot, unsigned int position, char array[])
{
    char temp_hold;
    bool debug = true;
    if (debug)
        cout << "Switching blocks " << robot << " with " << array[position] << endl;
    temp_hold = robot;
    robot = array[position];
    array[position] = temp_hold;
    return robot;
}
// Function test_empty
// This function tests the array to determine if a slot is empty (NULL)
// or if the slot contains a blank. The slot array must be intialized to
// all NULL or all blanks (spaces) before any blocks are added.
//
// Inputs:
// position - type unsigned int - index of slot to be tested
//
// Returns:
// true or false as value o function
// TRUE if slot is empty
// FALSE if the slot contains a block
//
// Example function call: if ( test_empty(index, array) )
//
bool test_empty(unsigned int position, char array[])
{
    char blank = ' '; // Blank space
    bool debug = true;
    if  (array[position] == NULL || array[position] == blank)
    {
        if (debug)
            cout << "Slot " << position << " empty. " << endl;
        return true;
    }
    else
    {
        if (debug)
            cout << "Slot " << position << " contains a block " << endl;
        return false;
    }

}


int main(){
	char block = get_block()
	char slot[20];
	//Put the first block from the chute INTO SLOT 10(hardware restriction)
	put_block(block, 10, slot);
	unsigned int counter = 1;
	bool checker = True;
	while(checker){
		cout << "Please enter another Block: "
		inblock = get_block();
		
		
		//Madison's Part
        for(int i = 0; i < 20; i++){
            if((!(test_empty(i,slot))) && (i != 20)){
                block = switch_blocks(block,i,slot);
                put_block(block,i+1,slot);
                block = NULL;

            }
            else if(i == 20){
                break;
            }
        }
		
		
		//Rishi's Part
		unsigned int index = 11, index2 = 11,right_counter = 0, left_counter = 0;
		bool check_if = false;
		int fill_count;
		fill_count = 10 - right_counter;
		char in_slot;
		bool debug = true;
		int dummy_count = -1;
		cout << "Please enter another Block: "
		inblock = get_block();
		check_if = robot_ltoreq_slot(inblock, block);
		if(!check_if){
			//Rishi::::::
			//We consider blocks that are greater than the block in slot 10
			//False should be returned
			
			if (test_empty(19, slot)){//if statement to check if slot 20 is empty
				
				while(index < 20){
					if(test_empty(index, slot)){//We now count the number of empty slots on the right side.
						right_counter++;
					}
					if(test_empty(index-11, slot)){//Counting the number of empty slots on the left side
						left_counter++;
					}
				index++;
				}
				
				if(left_counter > right_counter){//Move every block from slot 10 to the left by 1 using shift_block and place the input block in slot 10 using put_block
					to_left(slot);
					put_block(inblock, 10, slot);
				}
				else{//this means that the right_counter > left_counter, allowing us to target the right side 
					int position = 11;
					while(slot[position] != ' '){  //substitute for whitespace
					in_slot = slot[position - 1];
					debug = robot_ltoreq_slot(inblock, in_slot);
						if(debug == true){//Less than or equal to block
							while(dummy_count != fill_count){
							inblock = switch_blocks(inblock, position - 1, slot);
							//switch_blocks(block, position, slot);
							//print_slots(slot);
							shift_right(position++);
							dummy_count++;	
						}	
						break;
			
						position++;
			                                   // Input: 1 2 3 4 5 6 7 8 9 0 p r r s t u v 1 1 1
						}
						position++;
					}			
				}
			}
			
		
			else if(test_empty(0, slot)){//this part of the program is implemented if slot number 0 is empty:::
				while(index2 < 20){
					if(test_empty(index2, slot)){//We now count the number of empty slots on the right side.
						right_counter++;
					}
					if(test_empty(index2-11, slot)){//Counting the number of empty slots on the left side
						left_counter++;
					}
				index2++;
				}
				unsigned int dummyvar = -1;
				int position = 10;
				while(dummyvar != (10-left_counter)){
						inblock = switch_blocks(inblock, position - 1, slot);
						//switch_blocks(block, position, slot);
						print_slots(slot);
						shift_left(position);
						position--;			
						dummyvar++;
				}
					
			
			}		
			else{
				cout << "Error: More than 20 blocks have been inputted" << endl;
				break;
			}
		
			
		}
		
		
	}
		
}
	
		
		
	}
	


}
