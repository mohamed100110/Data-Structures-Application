#pragma once
#include <iostream>
#include <queue>
#include < stack>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
protected:

	string _Prefix;
	short _AverageTime = 0;
	int _TotalTicket = 0;
	struct stTicketInfo
	{
		string prefNum;
		int WaitingClient;
		string DateTime;
		int TimeRemender;
	};

	queue<stTicketInfo> _qTickets;
	queue<stTicketInfo> _qTempQueue;

public:

	clsQueueLine(string Prefix, short AverageTime)
	{
		_Prefix = Prefix;
		_AverageTime = AverageTime;
	}

	void IssueTicket()
	{
		_TotalTicket++;

		stTicketInfo Ticket;
		Ticket.prefNum = _Prefix + to_string(_TotalTicket);
		Ticket.DateTime = clsDate::GetSystemDateTimeString();
		Ticket.WaitingClient = WaitingClients();
		Ticket.TimeRemender = WaitingClients() * _AverageTime;

		_qTickets.push(Ticket);


	}

	void PrintInfo()
	{
		cout << "\n\t\t\t\t--------------------------------";
		cout << "\n\t\t\t\t           Queue Info           ";
		cout << "\n\t\t\t\t--------------------------------";
		cout << "\n\t\t\t\t  Prefix          = " << _Prefix;
		cout << "\n\t\t\t\t  Total Tickets   = " << _TotalTicket;
		cout << "\n\t\t\t\t  served Clients  = " << ServedClients();
		cout << "\n\t\t\t\t  Waiting Clients = " << WaitingClients();
		cout << "\n\t\t\t\t--------------------------------\n";

	}

	void PrintTicketsLineRTL()
	{
		if (_qTickets.empty())
			cout << "\n\t\tTickets:  No Tickets.";
		else
		{
			_qTempQueue = _qTickets;

			cout << "\n\t\tTickets:  ";
			while (!_qTempQueue.empty ())
			{
				cout << _qTempQueue.front().prefNum << " <-- ";
				_qTempQueue.pop();
			}
		}
		cout << "\n";

	}

	void PrintTicketsLineLTR()
	{
		if (_qTickets.empty())
			cout << "\n\t\tTickets:  No Tickets.";
		else
		{
			_qTempQueue = _qTickets;

			stack<stTicketInfo> Reverse ;
			while (!_qTempQueue.empty())
			{
				Reverse.push(_qTempQueue.front());
				_qTempQueue.pop();
			}
			cout << "\n\t\tTickets:  ";
			while (!Reverse.empty())
			{
				cout << Reverse.top().prefNum << " --> ";
				Reverse.pop();
			}
		}
		cout << "\n";
	}

	void PrintAllTickets()
	{
		_qTempQueue = _qTickets;

		cout << "\n\t\t\t\t          ---Tickets---        \n";
		if (_qTempQueue.empty())
	    cout << "\n\t\t\t\t        ---NO Tickets---\n";
		else
		{
			while (!_qTempQueue.empty())
			{
				cout << "\t\t\t\t--------------------------------\n";
				cout << "\t\t\t\t              " << _qTempQueue.front().prefNum << "\n\n";
				cout << "\t\t\t\t      " << _qTempQueue.front().DateTime << endl;
				cout << "\t\t\t\t      " << "waiting Clients = " << _qTempQueue.front().WaitingClient << endl;
				cout << "\t\t\t\t         Serve Time In\n";
				cout << "\t\t\t\t          " << _qTempQueue.front().TimeRemender << " Minutes.\n";
				cout << "\t\t\t\t--------------------------------\n";
				_qTempQueue.pop();
			}
		}
		cout << "\n";

	}

	bool ServeNextClient()
	{
		if (_qTickets.empty())
			return false;

		_qTickets.pop();
		return true;
	}

	int ServedClients()
	{
		return _TotalTicket - WaitingClients();
	}
	int WaitingClients()
	{
		return _qTickets.size();
	}

	string whoIsNext()
	{
		if (_qTickets.empty())
			return "No Clients Left.";
		else
			return _qTickets.front().prefNum;
	}
};

