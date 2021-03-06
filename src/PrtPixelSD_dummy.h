// -----------------------------------------
// PrtPixelSD_dummy.h
//
// Author  : R.Dzhygadlo at gsi.de
// -----------------------------------------

#ifndef PrtPixelSD_dummy_h
#define PrtPixelSD_dummy_h 1

#include "G4VSensitiveDetector.hh"
#include "TVector3.h"
#include <vector>
#include "TH2F.h"
class G4Step;
class G4HCofThisEvent;

/// Calorimeter sensitive detector class
///
/// In Initialize(), it creates one hit for each calorimeter layer and one more
/// hit for accounting the total quantities in all layers.
///
/// The values are accounted in hits in ProcessHits() function which is called
/// by Geant4 kernel at each step.

class PrtPixelSD_dummy : public G4VSensitiveDetector
{
  public:
    PrtPixelSD_dummy(const G4String& name,
                     const G4String& hitsCollectionName, 
                     G4int nofCells);
    virtual ~PrtPixelSD_dummy();
  
    // methods from base class
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
  G4int     fNofCells;



};

#endif
