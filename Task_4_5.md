Coammands used to perform task 4 and task 5:
git switch -c Temp:switch to the temp branch
touch Task_3.md: to create the readme file for task 3
git add Task_3.md
git commit -m "Task 4 completed: Added README.md for task 3"
git push
git push --set-upstream origin Temp
git switch main
git merge Temp:to merge the temp branch with the main branch 
touch Task_4_5.md
