#include "fsm.h"

//------------------------------------------------------------------------
// OBJECTS
//------------------------------------------------------------------------
StateMachine stateMachine(STATES_NUMBER, TRANSITION_NUMBER);

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
// Status actions
// This is not necessary, it is only there for debugging
void output_MODE1() {
	Serial.println("1   2   3   4");
	Serial.println("X            ");
	Serial.println();
}
// This is not necessary, it is only there for debugging
void output_MODE2() {
	Serial.println("1   2   3   4");
	Serial.println("    X        ");
	Serial.println();
}
// This is not necessary, it is only there for debugging
void output_MODE3() {
	Serial.println("1   2   3   4");
	Serial.println("        X    ");
	Serial.println();
}
// This is not necessary, it is only there for debugging
void output_MODE4() {
	Serial.println("1   2   3   4");
	Serial.println("            X");
	Serial.println();
}

void fsm_setup() {

    Serial.println("Initializing FSM...");

    // Configure transitions
    //(inputState, outputState, condition)
	stateMachine.AddTransition(MODE1, MODE2, []() { return button_mode == 1; });
	stateMachine.AddTransition(MODE2, MODE3, []() { return button_mode == 1; });
	stateMachine.AddTransition(MODE3, MODE4, []() { return button_mode == 1; });
	stateMachine.AddTransition(MODE4, MODE1, []() { return button_mode == 1; });

	// Configure status events
    // When it enters the state, it executes the function
    // This is not necessary, it is only there for debugging
	stateMachine.SetOnEntering(MODE1, output_MODE1);
	stateMachine.SetOnEntering(MODE2, output_MODE2);
	stateMachine.SetOnEntering(MODE3, output_MODE3);
	stateMachine.SetOnEntering(MODE4, output_MODE4);

    //The first state shall always be MODE_1
    stateMachine.SetState(MODE1, false, true);

}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void fsm_update(int *currentState) {

    Serial.println("Updating FSM...");
    stateMachine.Update();                      // Update the state machine
    *currentState = stateMachine.GetState();    // Get the current status

}
