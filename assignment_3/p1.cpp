//CS101 PROJECT1
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <limits>


using namespace std;

void printHelp();
void printColumns (const vector<string>& columns, int colWidth);
void printRows (const vector<vector<string> >& rows, int colWidth);
void search (const vector<vector<string> >& rows, const vector<string>& columns, const string& colName, const string& value, int colWidth);
void findMinMaxAvg (const vector<vector<string> >& rows, const vector<string>& columns, const string& colName, const string& operation);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " database.csv #col_width" << endl;
        return 1;
    }
string filename = argv[1];
int colWidth = stoi(argv[2]);

ifstream file(filename);
if (!file.is_open()) {
    cerr << "Failed to open \"" << filename << "\"" << endl;
    return 1;
}
string line;
vector<string> columns;
vector<vector<string> >rows;
while (getline(file, line)) {
    stringstream ss(line);
    string cell;
    vector<string> row;
    while (getline(ss, cell, ',')) {
            row.push_back(cell);
    }
    if (columns.empty()) {
        columns = row;
    } else{
        rows.push_back(row);
    }
}
file.close();
string command;
while (true) {
    cout <<"Enter command:";
    getline(cin, command);
    stringstream ss(command);
    string action;
    ss >> action;

    if (action == "quit") {
        break;
    } else if (action == "help") {
        printHelp();
    } else if (action == "print") {
        printRows(rows, colWidth);
} else if (action == "cols"){
    printColumns (columns, colWidth);
} else if (action == "search") {
    string colName, value;
    ss >> colName >> value;
    search(rows, columns, colName, value, colWidth);
} else if (action == "min"|| action == "max"|| action == "avg") {
    string colName;
    ss >> colName;
    findMinMaxAvg(rows, columns, colName, action);
} else {
    cerr <<"Invalid command" << endl;
    ss.ignore(numeric_limits<streamsize>::max(), '\n');
}

return 0;
}
}
void printHelp() {
    cout << "Possible Commands:"<<endl;
    cout << "quit" <<endl;
    cout << "help" <<endl;
    cout << "print" <<endl;
    cout << "cols" <<endl;
    cout << "search col_name value" <<endl;
    cout << "min col_name" <<endl;
    cout << "max col_name" <<endl;
    cout << "avg col_name" <<endl;
}
void printColumns(const vector<string>& columns, int colWidth) {
    for (const auto& column : columns) {
        cout << setw(colWidth) << column << endl;
    }
}
void printRows(const vector<vector<string> >& rows, int colWidth) {
    for (const auto& row : rows) {
        for (const auto& cell : row){
            cout << setw(colWidth) << cell;
        }
        cout << endl;
    }
}

//void search (const vector<vector<string> >& rows, const vector<string>& columns, const string& colName, const string& value, int colWidth) {
  //  bool found = false;
  //  int colIndex = -1;
   // for (size_t i = 0; i < columns.size(); ++i) {
    //    if (columns[i] == colName) {
   //         colIndex = i;
    //        break;
  //      }
   // }
  //  if (colIndex == -1){
  //      cerr << "Invalid column \""<<colName << "\"" << endl;
  //      return;
  //  }
  //  for (const auto&row : rows){
  //      if (colName == "*"){
 //          for (const auto& cell :row){
  //              if (cell == value){
  //                  printRows ({row} , colWidth);
  //                  found = true;
  //                  break;
 //               }
  //          }
 //      } else {
   //         if (row[colIndex]== value) {
  //              printRows ({row} , colWidth);
  //                  found = true;
    //        }
  //      }
   // }

    //if (!found) {
   //     cout << "No Results" << endl;
   // }
//}
void search(const vector<vector<string> >& rows, const vector<string>& columns, const string& colName, const string& value, int colWidth) {
    bool found = false;
    int colIndex = -1;

    // Find the index of the column
    for (size_t i = 0; i < columns.size(); ++i) {
        if (columns[i] == colName) {
            colIndex = i;
            break;
        }
    }

    if (colIndex == -1) {
        cerr << "Invalid column \"" << colName << "\"" << endl;
        return;
    }

    // Create the vector to hold the single row when printing
    std::vector<std::vector<std::string> > fake_rows;

    // Iterate through rows to find matches
    for (const auto& row : rows) {
        if (colName == "*") {  // Search in all columns
            for (const auto& cell : row) {
                if (cell == value) {
                    fake_rows.clear();    // Clear the vector before reuse
                    fake_rows.push_back(row);  // Add the single row to the vector
                    printRows(fake_rows, colWidth);  // Now pass fake_rows to printRows
                    found = true;
                    break;
                }
            }
        } else {  // Search by specific column
            if (row[colIndex] == value) {
                fake_rows.clear();    // Clear the vector before reuse
                fake_rows.push_back(row);  // Add the single row to the vector
                printRows(fake_rows, colWidth);  // Now pass fake_rows to printRows
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No Results" << endl;
    }
}



void findMinMaxAvg (const vector<vector<string> >& rows , const vector<string>& columns, const string& colName, const string& operation) {
    int colIndex = -1;
    for (size_t i = 0; i <columns.size(); ++i){
        if (columns[i]== colName){
            colIndex = i;
            break;
        }
    }
    if (colIndex == -1){
        cerr << "Invalid column \"" << colName << "\""<<endl;
        return;
    }
    double minVal = numeric_limits<double>::max();
    double maxVal = numeric_limits<double>::lowest();
    double sum = 0.0;
    int count = 0;

    for (const auto& row : rows){
        if (!row[colIndex].empty()){
            double val = stod(row[colIndex]);
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
            sum += val;
            ++count;
        }
    }
    if (count == 0) {
        cout <<"N/A"<<endl;
        return;
    }

    double avg = sum / count;

    if (operation =="min") {
        cout<<"The min for col \""<<colName<<"\"="<<minVal<<endl;
    } else if (operation == "max"){
        cout << "The max for col \""<<colName<< "\"=" << maxVal<< endl;
    
    } else if (operation == "avg"){
        cout << "The avg for col \""<<colName<< "\"=" << avg<< endl;
}
}
