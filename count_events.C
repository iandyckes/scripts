#include "TChain.h"
#include <iostream>

using namespace std;

void count_events(string dir, int twiki_entries, float xsec, float filter_eff, float k)
{
  TChain ch("Events");
  ch.Add(Form("%s/*.root",dir.c_str()));
  int entries = ch.GetEntries();

  float scale1fb = -99.;

  if( ch.GetAlias("evt_scale1fb") !=0 )
	{
	  scale1fb = (float)ch.GetMaximum("evt_scale1fb");
	}
  float twiki_scale1fb = xsec*filter_eff*k*1000./twiki_entries;

  cout << "\n" << dir << endl;
  if( twiki_entries == entries  ) cout<< Form(" %i sample entries,  %i twiki entries: Numbers match", entries, twiki_entries  )<<endl;
  else cout << Form(" %i sample entries,  %i twiki entries: THEY DON'T MATCH!!!!!!!", entries, twiki_entries  ) << endl;
  if( fabs(twiki_scale1fb - scale1fb)/twiki_scale1fb < 0.00001 ) cout<< Form(" %f sample scale1fb, %f twiki scale1fb: Numbers match", scale1fb, twiki_scale1fb )<<endl;
  else cout<< Form(" %f sample scale1fb, %f twiki scale1fb: THEY DON'T MATCH!!!!!!!", scale1fb, twiki_scale1fb )<<endl;
  cout << "\n";  
}
