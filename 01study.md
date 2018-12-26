# 卒業研究  
-- simulationを使用してLHCにおけるZ-bosonのfermionとのcouplingの大きさを測定する。  

* 使用するsimulationのソフト  
  * MG5_aMC  
  * LHAPDF  
  * HepMC  
  * Pythia8  
  * FastJet  
これらをインストールし、環境を整える。  

* 測定環境  
--LHCの実験環境に合わせる。  
陽子陽子をそれぞれ7TeVで衝突させる。一回の衝突で10000イベントであるため、今回はそれを10回測定し、イベントを10万イベント集める。   

* 事象の生成  
  `run/generate_event.sh`のファイルを使用して事象を生成する。今回はまず、陽子陽子衝突からタウレプトン対を生成し、MadGraphファイルの指定、ROOTファイルの生成、乱数の定義で生成する。  

  ```php  
  ./generate_event.sh 'p p > ta- ta+' event1 tautau.root 123456789  
  ```  
  今回は電弱相互作用のみのイベントのみが見たいので、ElectroWeakイベントを個別でシミュレーションで生成する。生成するイベントは次の通りである。  
  [1]pp>ta-ta+  
  [2]pp>ta-ta+j  
  [3]pp>ta-ta+jj  
  [4]p>ta-ta+jj[QCD=0]  


* 解析   
-- 解析は基本的にanalysisのディレクトリの中で行う。  
