echo "Enter commit comment\n"
read comment
git add . && git commit -m '$comment' && git push