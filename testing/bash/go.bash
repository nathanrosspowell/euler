
#!/bin/bash
pushd $1 1>/dev/null 
go run $2 
popd 1>/dev/null
