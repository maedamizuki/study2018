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
  `run/generate_event.sh`のファイルを使用して事象を生成する。今回はまず、陽子陽子衝突からタウレプトン対を生成し、MadGraphファイルの指定、ROOTファイルの生成、乱数の定義で生成する。  

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
ROOTの起動は、  
```php:terminal  
ROOT -l  
```  

ここで先ほどのtautau.rootファイルにROOT上で見たい時は、  
```php:terminal  
ROOT -l ../run/event1/tautau.root  
```  
とすると、ROOTファイルに入ることになる。  
この中で色々な物理量を見たい時は、`scan`の機能を使うと良い。粒子のx成分の運動量を見たい時は、  
```php:terminal  
t->Scan("event.Particle.mPx")  
```  
このように行うと、terminal上でx成分の運動量を表示することができたと思う。  
plotをして、グラフで見たい時は`Draw`の機能を行うとキャンバスにplotされたと思う。  

今回は、クラス化して解析用のファイルに自分でコードを書いていくことにする。  
```php:terminal  
TTree* t = dynamic_cast<TTree*>(gDirectory->Get("TTreeの名前"))  
t->MakeClass("クラス名")  
```  
とすると、クラスが作られ`クラス名.h`と`クラス名.C`というファイルが作られたと思う。  

上記の場合は、解析を行いたいROOTファイルが1つの場合は良いのだが、今回は10万イベント生成したため、10個のROOTファイルが存在する。そのため、`Chain`という機能を使って、次々とROOTファイルを読んでもらうようにする。  
```php:terminal  
TChain* chain = new TChain("")  
chain->Add("解析を行いたいROOTファイルの指定場所")  
chain->Add("")  
…  
chain->MakeClass("クラス名")  
```  
chain機能を使用して、クラス化を行うと、解析を行いたいファイルが全て入ったクラスを作ることができる。  
