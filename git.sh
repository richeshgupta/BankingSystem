echo "we are in :"
pwd
echo "Enter commit comment"
read comment
git add . && git commit -m '$comment'
echo "do you want to push now [y/n]"
read var
if [[ var =='y' ]]; then
	git push
fi
	exit