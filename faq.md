# DD ライブラリに関する FAQ

## SAPPOROBDD

### Invalid VarID のエラーメッセージが出る

関数呼び出し時に以下のエラーメッセージが出ることがあります。

```
***** ERROR  bddxxx: Invalid VarID ( 0x?? ) *****
 NodeLimit : ???	 NodeSpc : ???	 VarSpc : ???
 CacheSpc : ???	 NodeUsed : ???	 VarUsed : ???
```

その場合、以下を確認してください。

- BDD_NewVar 関数が必要な回数呼び出されている
	- BDD_NewVar 関数（または BDD_NewVarOfLev 関数）は使用する変数の個数の回数以上、事前に呼び出す必要があります。BDD_NewVar 関数を呼び出した回数は、エラーメッセージの VarUsed の欄に表示されます。この値以上の変数を使おうとしていないか確認してください。
