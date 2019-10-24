// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"

namespace Rivet {


  /// @brief Add a short analysis description here
  class ALICE_2015_I1357424 : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(ALICE_2015_I1357424);


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {

      // Initialise and register projections
      declare(FinalState(Cuts::abseta < 5 && Cuts::pT > 100*MeV), "FS");

      // Book histograms
      // _h_XXXX = bookHisto1D(1, 1, 1);
      // _p_AAAA = bookProfile1D(2, 1, 1);
      // _c_BBBB = bookCounter(3, 1, 1);

      // plots from the paper
      _histPtPions      = bookHisto1D("d01-x01-y01");    // pions
      _histPtKaons      = bookHisto1D("d01-x01-y02");    // kaons
      _histPtProtons    = bookHisto1D("d01-x01-y03");    // protons
      _histPtKtoPi      = bookScatter2D("d02-x01-y01");  // K to pi ratio
      _histPtPtoPi      = bookScatter2D("d03-x01-y01");  // p to pi ratio

      // temp histos for ratios
      _histPtPionsR1    = bookHisto1D("TMP/pT_pi1", refData(2, 1, 1)); // pi histo compatible with more restricted kaon binning
      _histPtPionsR2    = bookHisto1D("TMP/pT_pi2", refData(3, 1, 1)); // pi histo compatible with more restricted proton binning
      _histPtKaonsR     = bookHisto1D("TMP/pT_K",   refData(2, 1, 1)); // K histo with more restricted binning
      _histPtProtonsR   = bookHisto1D("TMP/pT_p",   refData(3, 1, 1)); // p histo with more restricted binning


      const ChargedFinalState cfs(Cuts::absrap < 0.5);
      addProjection(cfs, "CFS");


    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      /// @todo Do the event by event analysis here

    }


    /// Normalise histograms etc., after the run
    void finalize() {

      // normalize(_h_YYYY); // normalize to unity
      // scale(_h_ZZZZ, crossSection()/picobarn/sumOfWeights()); // norm to cross section

    }

    //@}


    /// @name Histograms
    //@{
    // Histo1DPtr _h_XXXX, _h_YYYY, _h_ZZZZ;
    // Profile1DPtr _p_AAAA;
    // CounterPtr _c_BBBB;
    //@}


    // histograms for spectra
    Histo1DPtr _histPtPions;
    Histo1DPtr _histPtProtons;
    Histo1DPtr _histPtKaons;

    // temporary histograms for ratios
    Histo1DPtr _histPtPionsR1;
    Histo1DPtr _histPtPionsR2;
    Histo1DPtr _histPtProtonsR;
    Histo1DPtr _histPtKaonsR;

    // scatter plots for ratios
    Scatter2DPtr _histPtKtoPi;
    Scatter2DPtr _histPtPtoPi;



  };


  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(ALICE_2015_I1357424);


}
