# HepMcのコンパイルの仕方  

-- 今回の研究では、共通のデータ構造を規定したC++ライブラリをHepMC3.0.0で行う。この際に、HepMCを自分の作業を行うディレクトリにコンパイルを完了して、使用できる状態にする必要がある。  

一度、自分のsshのアカウントにログインした後、SLC6で動かす場合には、ROOT6とcmakeを最新のversionにsetする必要がある。  
```php:terminal  
setupATLAS  
lsetup root6  
lsetup cmake  
```  
上記のように行い、解析を行える環境を整える。  

# コンパイルの流れ  
HepMC3のコンパイルは以下のように行う。  
```php:terminal  
git clone https://gitlab.cern.ch/hepmc/HepMC3.git   
mkdir hepmc3-build  #コンパイルの作業はソースコードを管理しているディレクトリとは別のところで行うようにする。  
cd hepmc3-build  
cmake ../HepMC3<option>  
make install  
```  
この際のoptionについては、以下のようにoptionを使用する。　　
```php:terminal  
cmake -DHEPMc_ENABLE_ROOTIO=ON \  
-DROOT_DIR=$ROOTSYS \  
-DHEPMC_INSTALL_INTERFACES=ON \  
-DHEPMC_BUILD_EXAMPLES=ON \  
-DCMAKE_INSTALL_PREFIX=$SWDIR \  
../HepMC3  
```
