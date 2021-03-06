#ifndef _MyTestingProcessor_hh_
#define _MyTestingProcessor_hh_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "Calorimeter.hh"
#include "ClusterOperator.hh"
#include <string>
#include <iostream>
#include <marlin/Processor.h>
#include <vector>
#include <EVENT/CalorimeterHit.h>
#include <values.h>
#include <EVENT/MCParticle.h>
#include "TCluster.hh"

#include "TFile.h"
#include "TTree.h"
using namespace lcio;
namespace CALICE {
                                                              
  /** A processor to find the outgoing particles (mip) 
   * in the last layers of the SiW Ecal
   * Author: Bilokin Sviatoslav @ LAL 2012/13
   */

  class MyTestingProcessor : public marlin::Processor
  {
  public:
    Processor*  newProcessor() { return new MyTestingProcessor ; }

    MyTestingProcessor();

    ~MyTestingProcessor() {};


    /** Called at the begin of the job before anything is read.
     * Use to initialize the processor, e.g. book histograms.
     */
    void init();
    /** Called for every run, e.g. overwrite to initialize run dependent 
     *  histograms.
     */
    void processRunHeader( LCRunHeader* run);

    /** Called for every event - the working horse. 
     */
    void processEvent( LCEvent * evtP );

    //Called at the end of the job
    void end();

  protected:

    std::string _colName;              /**< name of the hit input collection (Marlin processor parameter)*/

  private:
	void processCalorimeterHits(int InteractionZ, int numberOfHits);
	void writeCalorimeter(int numberOfHits);
	void writeZone();
	void ClearVariables();
	void writeClusters(MyCalorimeter::ClusterOperator & opera);
	//bool applyPrimaryCutsTo(MCParticle * particle);
	//void writeParticle(MCParticle * particle, int i);
	//int applyIntegrationCuts(const vector<MCParticle*> & particle);
	//vector<float> getPointAtCalorimeter(const double * start, const double * end);
	float maxminPosition[3][2];
	std::vector< float > energyDeposition;
        int EventNumber;
        int TotalEventNumber;
	int LastFiredPadsNumber;
	int LastEventsFromLayer;
	int FirstInteractionLayer;
	int LowerInteractionLayer;
	int RequireInteraction;
	int RejectDoubleEvents;
	float MIPEnergyCut;
	float epsilonCut;
	int hitsCut;
	TFile* hfile ;
        std::string _hfilename ;
        std::string filename ;
        TTree* _Tree;
        TTree* _InteractionTree;
        TTree* _ClusterTree;
        //TTree* _MCTree;
        static const int MAXN = 10000 ;
        static const int MINN = 1000 ;
        int _posx[MAXN];   // hit position x, in mm, 0 is the center of ECAL
        int _posy[MAXN];   // hit position y, in mm, 0 is the center of ECAL
        int _posz[MAXN];   // hit position z, in mm, starting at the frount of ECAL
	float _energyHit[MAXN];
	float _energyHit_exc[MAXN];
	float _energyDep[30];
	float _totalEnergy;
	vector< vector< float > > * volumeECal;
	int _tracksCount;
	int _clustersTotal;
	int _showerCount;
	int _count;			
	int _nhits;	
	int goodEventCount;
	int _interaction;
	float _sigma[MINN];
	float _module[MINN];
	int _number[MINN];
	int _type[MINN];
	int _startY[MINN];
	int _startX[MINN];
	int _startZ[MINN];
	int _endY[MINN];
	int _endX[MINN];
	int _endZ[MINN];
	float _teta[MINN];
	float _phi[MINN];
	float _ecluster[MINN];
	int _nspads;
	int _posx2[MINN]; // hit position x, in mm, 0 is the center of ECAL
	int _posy2[MINN]; // hit position y, in mm, 0 is the center of ECAL
	int _posz2[MINN]; // hit position z, in mm, starting at the frount of ECAL
	MyCalorimeter::TCluster _clusters[MAXN];

	int _ipads;
	int _iposx[MINN]; // hit position x, in mm, 0 is the center of ECAL
	int _iposy[MINN]; // hit position y, in mm, 0 is the center of ECAL
	int _iposz[MINN]; // hit position z, in mm, starting at the frount of ECAL
	float _ix[MINN]; // hit position x, in mm, 0 is the center of ECAL
	float _iy[MINN]; // hit position y, in mm, 0 is the center of ECAL
	float _iz[MINN]; // hit position z, in mm, starting at the frount of ECAL
	float _ienergyHit[MAXN];

	int _nclusters;
	int _nclusterpads[MINN];
	int _clustertype[MINN];
	int _clusterendX[MINN];
	int _clusterendY[MINN];
	int _clusterendZ[MINN];
	int _clusterstartX[MINN];
	int _clusterstartY[MINN];
	int _clusterstartZ[MINN];

	float _clustertheta[MINN];
	float _clusterphi[MINN];
	float _clusterlength[MINN];
	float _clusterpadenergy[MINN][MINN];
	MyCalorimeter::Calorimeter ECalCopy;
	MyCalorimeter::Calorimeter ECal;
	std::vector< std::vector< float > > Coordinates;
  };

}


#endif
