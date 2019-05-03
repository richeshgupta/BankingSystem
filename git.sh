echo "Enter commit comment"
read comment
git add . && git commit -m '$comment' && git push