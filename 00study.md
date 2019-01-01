#### ターミナル上での操作  
-- sshの研究室のアカウントにログインした後、解析を開始するまでの行う操作をまとめる。  

一度setupを行う  
`setupATLAS`  
`lsetup root`  
`lsetup cmake`  
を行い、cmake、ROOTを行えるように設定を行う。  

次に、自分のアカウントのworkのディレクトリに入り、研究を進める環境の場所に移動する。  
その後、  
`source ./script/setup.sh`  
で、解析ファイルに場所の指定をincludeできる。  
