#include <iostream>

using namespace std;

//existing class of the subsystem
class MisDepartment
{
  public:
    void submitNetworkRequest()
    {
        _state = 0; //represents current state
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete) //only returns true when completes the job
          return 1;
        return 0;
    }
  private:
    enum States
    {
       // possible states of MIS Department 
        Received, DenyAllKnowledge, ReferClientToFacilities,
          FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
          ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
          FixElectriciansWiring, Complete
    };
    int _state;
};

//existing class of the subsystem
class ElectricianUnion
{
  public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    // whenever we call this method it will go moving on the enumerator States. it keeps moving to the next satte until it reaches complete
    {
        _state++;
        if (_state == Complete) 
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
          WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
          DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
          TurnInThePaperwork, Complete
    };
    int _state;
};

//existing class of the subsystem
class FacilitiesDepartment
{
  public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++; //every time this method is called, this increments to move on to the next phase until job is done 
        if (_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {   
      // needs to go one by one to complete job
        Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
          EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
          ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
          EngineerFillsOutPaperWork, Complete
    };
    int _state;
};

//implement Facade DP
class FacilitiesFacade
{
  public:
    FacilitiesFacade()
    {
        _count = 0;
    }
    void submitNetworkRequest()
    {
        _state = 0; // 0 is received
    }
    bool checkOnStatus() // move on to each department to complete the job
    {
        _count++; // represent the number of phone calls, how many time this method was called
        /* Job request has just been received */
        // submit request to the correct department
        if (_state == Received)
        {
            _state++; 
            /* Forward the job request to the engineer */
            _engineer.submitNetworkRequest();
            cout << "submitted to Facilities - " << _count << 
              " phone calls so far" << endl;
        }
        else if (_state == SubmitToEngineer)
        {
            /* If engineer is complete, forward to electrician */
            if (_engineer.checkOnStatus()) // this needs to return true to execute next block
            {
                _state++;
                _electrician.submitNetworkRequest();
                cout << "submitted to Electrician - " << _count << 
                  " phone calls so far" << endl;
            }
        }
        else if (_state == SubmitToElectrician)
        {
            /* If electrician is complete, forward to technician */
            if (_electrician.checkOnStatus())
            {
                _state++;
                _technician.submitNetworkRequest();
                cout << "submitted to MIS - " << _count << 
                  " phone calls so far" << endl;
            }
        }
        else if (_state == SubmitToTechnician)
        {
            /* If technician is complete, job is done */
            if (_technician.checkOnStatus())
              return 1; // the whole process is complete
        }
        /* The job is not entirely complete */
        return 0;
    }
    int getNumberOfCalls()

    {
        return _count; // represent the number of phone calls
    }
  private:
    enum States
    { 
       // each state represents the stage of the process
        Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
    };
    int _state;
    int _count;
    //instances to all classes it hides, the logic of interacting with all classes are wrapped inside facade, hidden from the client
    FacilitiesDepartment _engineer;
    ElectricianUnion _electrician; //instance of electritian union
    MisDepartment _technician;
};

//represents client
int main()
{
  FacilitiesFacade facilities; //only interacts with facade class

  facilities.submitNetworkRequest();
  /* Keep checking until job is complete */
  while (!facilities.checkOnStatus()) // when returns 1, the job is complete
    ;
  cout << "job completed after only " << facilities.getNumberOfCalls() << 
    " phone calls" << endl;
}

/*
 Client communicates with facilities to fix something. 
 Facade class records the number of phone calls that 
 will take from submitting request, contacting departments, 
 and complete fixing the problem
 */
