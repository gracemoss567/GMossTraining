# HPC-Training-Challenges

This repository acts as a template for the challenges associated with Monash DeepNeuron's HPC Training Content.

## About Challenges

As you progress through each chapter you will be given a small set of challenges to complete. In order to complete the challenges there is a complementary GitHub template repository found on the Monash DeepNeuron GitHub organisation called [HPC Training Challenges](https://github.com/MonashDeepNeuron/HPC-Training-Challenges). As a template you are able to create your own copy of the repository and complete the challenges completely independent of the other recruits.

## Setting Up Challenges Repository

To get setup:

- Click the link above to got to the repository on GitHub.
- Click 'Use this template' button (green) and select 'Create a new repository'.
- Give it a name and make sure it is private.
- Ensure you are copying it to your personal account and not the Monash DeepNeuron organisation. There will be a dropdown next to where you give the repo a name from which you can select your account.
- Click 'Create repository from template'.
- This will open the page for the repository. Click the '<> Code' button (green), make sure you are in the HTTPS tab and copy the link.
- Open a terminal in your dev directory.
- Run:

```sh
git clone <repo-link>
cd <repo-name>
git remote add upstream <repo-link>
git remote set-url --push upstream DISABLE
code .
```

This will clone the repository into you current working directory maintaining its link to its `origin` (your remote copy on GitHub) allowing you to sync changes between you local and remote copies. This also sets up a link called `upstream` to the original template directory with pushing disabled. This allows you to sync the base of the repository with your copy, similar to a fork but prevents changes from being pushed to the template.

Once you completed a challenge or made some changes you want to save to your remote repository you can simply add to a commit stage, combine the changes in a commit and then push the commit to `origin`.

```sh
git add .               # Add any untracked or modified files
git commit -m "msg"     # Commit changes locally with a message
git push origin         # Push to GitHub
```

If you need to sync your local repository with the remote version you can either fetch the changes to add them to the logs without modifying the codebase or pull them to integrate the changes into your version.

```sh
git fetch origin    # Sync changes with remote without integrating (downloading) them
git pull origin     # Sync and integrate remote changes locally
```

> Note:
>
> - If you need to sync changes from the template repository use the same commands but replace `origin` with `upstream`.

## Challenges Repository Structure

The challenges repository is broken down into different directories for each chapter. For each chapter their will be a series of additional directories corresponding to the specific challenge. These will contain any and all the resources needed for the challenge except programs that you are required to complete.

<!-- For some of the challenges, GitHub will have some automatic tests that run when you push your changes back up to GitHub. -->

## Adding Trainers as Collaborators for Assessment

You will need to add the HPC Training team as contributors to your copy of the repository as it is private meaning we cannot access it otherwise. To add us, open the repos GitHub page (your copy not Monash DeepNeuron's) and navigate to the settings tab. On the options list to the left you'll click the 'collaborators' option. There will be a green button labelled 'Add people'. Click this to bring up the pop-up. Add the following usernames as collaborators (they may need to be entered separately).

- @oraqlle
- @Ozzywap
- @UnciaBit
- @jasparm
