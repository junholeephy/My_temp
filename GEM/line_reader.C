void line_reader()
{
 //   TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
 //   dir.ReplaceAll("n9_twograph_one.C","");
 //   dir.ReplaceAll("/./","/");

//    ifstream vInput;
//    vInput.open(Form("%s2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat",dir.Data()));
	ifstream infile("2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat");
	int n=0;
	char str[10000];
	while(!infile.eof())
	{
		 infile.getline(str, sizeof(str));//此处默认的终止标识符为‘\n’
		  n++;
	}
	cout<<n<<endl;
//	infile.Close();
}
