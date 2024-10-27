# atcoder
atcoderのコードを保管

### ディレクトリからtestsフォルダを削除

```
find . -type d -name "tests" -exec rm -rf {} +
```

### ディレクトリからa.outファイルを削除

```
find . -type f -name "a.out" -exec rm -f {} +
```

### ディレクトリからcontest.acc.jsonファイルを削除

```
find . -type f -name "contest.acc.json" -exec rm -f {} +
```