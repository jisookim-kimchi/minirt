#!/bin/bash

# Set the source branch and destination base directory
SOURCE_BRANCH="jisoo"
DESTINATION_PLACE_1="math"
DESTINATION_PLACE_2="object"

COPIED_FILES=()

# List of files what you want to copy from the source branch
FILES_1=(
	"trace.c"
	"vector2.c"
	"vector3.c"
	"vector4.c"
	"vector_struct.h"
)

FILES_2=(
	"obejct/plane.h"
)

# Print out the Current branch name make sure the files will be copied to the right place
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
echo "Copying files from '$SOURCE_BRANCH' to '$CURRENT_BRANCH' in 
	'$DESTINATION_PLACE_1', '$DESTINATION_PLACE_2'..."

mkdir -p "$DESTINATION_PLACE_1"
mkdir -p "$DESTINATION_PLACE_2"

for FILE_1 in "${FILES_1[@]}"; do
	echo "Checking out $FILE_1 from $SOURCE_BRANCH..."
	git checkout "$SOURCE_BRANCH" -- "$FILE_1" || {
		echo "Failed to checkout $FILE_1"
		continue
	}

	DESTINATION_PATH_1="$DESTINATION_PLACE_1/$(basename "$FILE_1")"
	echo "Moving $FILE_1 to $DESTINATION_PATH_1..."
	mkdir -p "$(dirname "$DESTINATION_PATH_1")"
	mv "$FILE_1" "$DESTINATION_PATH_1"
	COPIED_FILES+=("$DESTINATION_PATH_1")

done

for FILE_2 in "${FILES_2[@]}"; do
	echo "Checking out $FILE_2 from $SOURCE_BRANCH..."
	git checkout "$SOURCE_BRANCH" -- "$FILE_2" || {
		echo "Failed to checkout $FILE_2"
		continue
	}

	DESTINATION_PATH_2="$DESTINATION_PLACE_2/$(basename "$FILE_2")"
	echo "Moving $FILE_2 to $DESTINATION_PATH_2..."
	mkdir -p "$(dirname "$DESTINATION_PATH_2")"
	mv "$FILE_2" "$DESTINATION_PATH_2"
	COPIED_FILES+=("$DESTINATION_PATH_2")

done

echo
echo "✅ The following files were successfully copied:"
for FILE in "${COPIED_FILES[@]}"; do
	echo " - $FILE"
done

echo "All files copied. You can now stage and commit the changes:"

# Build commit message from copied files
COMMIT_MSG="Copied the following files from $SOURCE_BRANCH to $CURRENT_BRANCH:\n"

for FILE in "${COPIED_FILES[@]}"; do
	COMMIT_MSG+="- $FILE\n"
done

# Escape the message for safe passing to git
echo -e "\nReady to commit with message:"
echo -e "$COMMIT_MSG"

echo -e "\nRun the following command to commit:"
echo "  git add $DESTINATION_PLACE_1 $DESTINATION_PLACE_2"
echo -e "  git commit -m \$'$COMMIT_MSG'"
