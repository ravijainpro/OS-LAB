// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	// ftok to generate unique key 
	key = ftok("progfile", 65); 
	// ftok() , which converts a filename to a key value that is unique within the system. Functions that initialize or get access to messages

	// msgget creates a message queue 
	// and returns identifier 
	/*
	Processes requesting access to an IPC facility must be able to identify it. 
	To do this, functions that initialize or provide access to an IPC facility use a key_t key argument. 
	(key_t is essentially an int type defined in <sys/types.h> 
	*/
	msgid = msgget(key, 0666 | IPC_CREAT); 
	//When the IPC_CREAT flag is supplied in the flags argument appropriate to the call, the function tries to create the facility if it does not exist already. 
	//The Message queue is created with a basic key and message flag msgid = IPC_CREAT | 0666 -- create queue and make it read and appendable by all. 
	message.mesg_type = 1; 

	printf("Write Data : "); 
	gets(message.mesg_text); 

	// msgsnd to send message 
	msgsnd(msgid, &message, sizeof(message), 0); 

	// display the message 
	printf("Data send is : %s \n", message.mesg_text); 

	return 0; 
} 
